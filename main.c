#include "DAVE.h"                 //Declarations from DAVE Code Generation (includes SFR declaration)
#include "scpi/scpi.h"
#include "scpi-def.h"
#include <math.h>

// todo: Implement watchdog timer to ensure code has not crashed
// todo: Current sensor implementation

volatile uint32_t zeroCurrentVoltage = 0; // Global variable to store zero current ADC value
volatile float lastCycleRmsCurrent = 0; // Global variable to store last cycle's RMS current

#define MAX_SAMPLES 2100 // Adjust based on expected max number of samples per half cycle
volatile uint16_t adcValues[MAX_SAMPLES];
volatile uint16_t sampleCount = 0;
int measureCurrent = 0;

#define ADC_MAX 4096
#define REF_VOLTAGE 3300
#define MV_PER_AMP 400

#ifdef XMC_DEBUG_ENABLE
extern void initialise_monitor_handles(void);
#endif

volatile int zcdLastCount = 0;
int zcdLiveCount = 0;

size_t SCPI_Write(scpi_t * context, const char * data, size_t len) {
	(void) context;
	tcp_write(context->user_context, data, len, 1);
	return len;
}

scpi_result_t SCPI_Flush(scpi_t * context) {
	(void) context;
	tcp_output(context->user_context);
	return SCPI_RES_OK;
}

int SCPI_Error(scpi_t * context, int_fast16_t err) {
	(void) context;
	XMC_DEBUG("ERROR!\r\n");
	return 0;
}

scpi_result_t SCPI_Control(scpi_t * context, scpi_ctrl_name_t ctrl, scpi_reg_val_t val) {
	(void) context;
	return SCPI_RES_OK;
}

scpi_result_t SCPI_Reset(scpi_t * context) {
	(void) context;
	XMC_DEBUG("** RESET COMMAND\r\n");
	// todo: Implement instrument settings reset.
	return SCPI_RES_OK;
}

static err_t client_recv(void *arg, struct tcp_pcb *pcb, struct pbuf *p, err_t err) {
	char buffer[1024] = {0};

	// if pbuf isnt NULL, we have received data.
	if (p != NULL) {
		pbuf_copy_partial(p, buffer, p->len, 0);
		tcp_recved(pcb, p->tot_len);
		SCPI_Input(&scpi_context, buffer, strlen(buffer));
		pbuf_free(p);
	}
	// if pbuf is NULL, then the remote host closed the connection
	else if (err == ERR_OK) {
		tcp_arg(pcb, NULL);
		tcp_sent(pcb, NULL);
		tcp_recv(pcb, NULL);
		tcp_close(pcb);
	}

	return ERR_OK;
}

static err_t client_accept(void *arg, struct tcp_pcb *newpcb, err_t err) {
	tcp_recv(newpcb, client_recv);
	XMC_DEBUG("** NEW CONNECTION\r\n");
	scpi_context.user_context = newpcb;
	return ERR_OK;
}


void manageLighting()
{
	for(int i = 0; i < 18; i++) {
	  if (lightingChannels[i] == 1 &&  // channel is currently on
		  dimmingChannels[i] > 0 &&  // channel has dimming enabled
		  zcdLiveCount >= dimmingChannels[i]) { // zero counter has exceeded calculated dimming value

		  // channel off
		  lightingChannels[i] = 0;
		  DIGITAL_IO_SetOutputHigh(channels[i]);
	  }
	}
}

void calculateInitialZeroCurrentVoltage(void) {
    uint32_t sum = 0;
    const uint32_t samples = 1000; // Number of samples for averaging

    for (uint32_t i = 0; i < samples; i++) {
        sum += ADC_MEASUREMENT_GetResult(&ADC_MEASUREMENT_Channel_A); // Accumulate ADC readings

        XMC_DelayUs(7); // Small delay to account for long sample time configured
    }
    zeroCurrentVoltage = sum / samples; // Compute average

    measureCurrent = 1;
}


/**

 * @brief main() - Application entry point
 *
 * <b>Details of function</b><br>
 * This routine is the application entry point. It is invoked by the device startup code. It is responsible for
 * invoking the APP initialization dispatcher routine - DAVE_Init() and hosting the place-holder for user application
 * code.
 */

int main(void)
{
  DAVE_STATUS_t status;

#ifdef XMC_DEBUG_ENABLE
  initialise_monitor_handles();
  XMC_DEBUG("MAIN\r\n");
#endif

  status = DAVE_Init(); // Initialization of DAVE APPs
  XMC_DEBUG("STARTUP\r\n");

  if (status != DAVE_STATUS_SUCCESS)
  {
    /* Placeholder for error handler code. The while loop below can be replaced with an user error handler. */
    XMC_DEBUG("DAVE APPs initialization failed\n");

    while(1U) { }
  }

  // Setup network communication
  struct tcp_pcb *pcb = tcp_new();
  tcp_bind(pcb, IP_ADDR_ANY, 5025);
  pcb = tcp_listen(pcb);
  tcp_accept(pcb, client_accept);

  // setup SCPI command handling
  scpi_context.user_context = pcb;
  SCPI_Init(&scpi_context,
		  scpi_commands,
		  &scpi_interface,
		  scpi_units_def,
		  SCPI_IDN1, SCPI_IDN2, SCPI_IDN3, SCPI_IDN4,
		  scpi_input_buffer, SCPI_INPUT_BUFFER_LENGTH,
		  scpi_error_queue_data, SCPI_ERROR_QUEUE_SIZE);

  // measure average voltage for 0 current sense
  calculateInitialZeroCurrentVoltage();

  // Enable dimming interrupt
  INTERRUPT_Enable(&DIMMING_INTERRUPT);

  DIGITAL_IO_SetOutputHigh(&LED2);

  while(1U)
  {
	  // if stops after 1hr, interesting post here: https://community.infineon.com/t5/DAVE/LWIP-stops-working-after-about-one-hour/td-p/306176
	  sys_check_timeouts(); // process things like LWIP timeouts

	  manageLighting();
  }
}

void ZeroCrossingISR(void)
{
	zcdLastCount = zcdLiveCount;
	zcdLiveCount = 0;

	// move to main loop?
	for(int i = 0; i < 18; i++) {
		if (lightingChannels[i] == 0 && // lighting channel is not already enabled
			dimmingChannels[i] > 0) { // channel has dimming enabled

			lightingChannels[i] = 1; // switch lighting channel on
			DIGITAL_IO_SetOutputLow(channels[i]);
		}
	}

	// RMS Current calculation
	if (measureCurrent && sampleCount > 0)
	{
		uint64_t sumOfSquares = 0;
		for (uint32_t i = 0; i < sampleCount; i++) {
			sumOfSquares += (uint64_t)(adcValues[i] * adcValues[i]);
		}

		// calculate RMS current - convert ADC value to millivolts, then convert that to amps.
		lastCycleRmsCurrent = ((sqrt(sumOfSquares / sampleCount) / ADC_MAX) * REF_VOLTAGE) / MV_PER_AMP;
	} else {
		lastCycleRmsCurrent = 0;
	}
	sampleCount = 0; // Reset for the next half cycle
}

void DimmingISR(void) // running on TIMER_0, 1uS
{
	zcdLiveCount++;

	// Prevent buffer overflow - will trip if ZCD is less than 33hz or there is no zero crossing
	if (zcdLiveCount > 30000) {
		zcdLiveCount = 0;
		zcdLastCount = 0;
	}
}

void ACMeasurementISR(void) {
    if (measureCurrent && zcdLastCount > 0 && sampleCount < MAX_SAMPLES) {
        adcValues[sampleCount++] = abs(ADC_MEASUREMENT_GetResult(&ADC_MEASUREMENT_Channel_A) - zeroCurrentVoltage);
    }
}

