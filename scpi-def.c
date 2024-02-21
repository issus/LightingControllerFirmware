/*-
 * BSD 2-Clause License
 *
 * Copyright (c) 2012-2018, Jan Breuer
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * * Redistributions of source code must retain the above copyright notice, this
 *   list of conditions and the following disclaimer.
 *
 * * Redistributions in binary form must reproduce the above copyright notice,
 *   this list of conditions and the following disclaimer in the documentation
 *   and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/**
 * @file   scpi-def.c
 * @date   Thu Nov 15 10:58:45 UTC 2012
 *
 * @brief  SCPI parser test
 *
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "DAVE.h"
#include "scpi/scpi.h"
#include "scpi-def.h"

#define NUM_CHANNELS 18

// Channels array to simplify operations on digital IOs
const DIGITAL_IO_t* channels[] = {&OUT_CH1, &OUT_CH2, &OUT_CH3, &OUT_CH4, &OUT_CH5, &OUT_CH6,
                                  &OUT_CH7, &OUT_CH8, &OUT_CH9, &OUT_CH10, &OUT_CH11, &OUT_CH12,
                                  &OUT_CH13, &OUT_CH14, &OUT_CH15, &OUT_CH16, &OUT_CH17, &OUT_CH18};

// State and dimming arrays to manage light and dimming states
int lightingChannels[NUM_CHANNELS] = {0};// Initialize all channels to off (0)
int dimmingChannels[NUM_CHANNELS] = {0}; // Initialize all dimming times to 0

// Calculate dimming value based on brightness percentage
int calculateDimming(float percentage)
{
	// note: dimming is percentage of full brightness to dim
	// so 1 is off, 0 is fully on. 0.7 is 70% dimmer than full brightness (ideally)

    if (percentage <= 0) return 10000; // fully on

    if (percentage >= 1) return 0; // fully off

    // Scale the input percentage to stay within the 0-75% range
	// If the input percentage is above 75%, it is scaled down to 75%
	// This ensures the dimming stays within the stable range of the lamps
    float scaledPercentage = percentage * 0.75; // Cap the percentage at 75% for stability

    float phase_angle = acos(sqrt(scaledPercentage));  // Calculate the phase angle based on the percentage

    // Calculate the ON time based on the phase angle and actual zero crossing interval
    // Assuming 10000 represents the total count for a full cycle (0% dimming) - 10000us == 50hz
    //int on_time = zcdLastCount * (phase_angle / M_PI);
    return (int)(10000 * (phase_angle / M_PI));
}

// Helper function to set channel state and dimming value
void setChannelState(int channelIndex, int state, int dimValue) {
    if (state) {
        DIGITAL_IO_SetOutputLow((DIGITAL_IO_t*)channels[channelIndex]);
    } else {
        DIGITAL_IO_SetOutputHigh((DIGITAL_IO_t*)channels[channelIndex]);
    }

    lightingChannels[channelIndex] = state;
    dimmingChannels[channelIndex] = dimValue;
}

static scpi_result_t IO_Btn(scpi_t * context) {
	XMC_DEBUG("## IO_BTN\r\n");
	uint32_t buttonState = DIGITAL_IO_GetInput(&BUTTON1);
	SCPI_ResultBool(context, buttonState != 1);
	return SCPI_RES_OK;
}

static scpi_result_t ZCD_ValueQuery(scpi_t * context) {
	XMC_DEBUG("## ZCD_Value?\r\n");
	SCPI_ResultInt32(context, zcdLastCount);
	return SCPI_RES_OK;
}

static scpi_result_t CurrentSense_Query(scpi_t * context) {
	XMC_DEBUG("## CurrentSense_Query?\r\n");
	SCPI_ResultInt32(context, lastCycleRmsCurrent * 1000);
	return SCPI_RES_OK;
}

#ifdef XMC_DEBUG_ENABLE
static scpi_result_t ZCD_ValueSet(scpi_t * context) {
	XMC_DEBUG("## ZCD_Value\r\n");

	int32_t newZcd = 0;

	if (SCPI_ParamInt32(context, &newZcd, TRUE)) {
		zcdLastCount = newZcd;
	} else {
		return SCPI_RES_ERR;
	}

	return SCPI_RES_OK;
}
#endif

static scpi_result_t IO_Led(scpi_t * context) {
	scpi_bool_t param1;

	XMC_DEBUG("## IO_LED\r\n");

	// parse the bool
	if (SCPI_ParamBool(context, &param1, TRUE)) {
		if (param1) {
			XMC_DEBUG(" - LED ON\r\n");
			DIGITAL_IO_SetOutputHigh(&LED2);
		} else {
			XMC_DEBUG(" - LED OFF\r\n");
			DIGITAL_IO_SetOutputLow(&LED2);
		}
	} else {
		return SCPI_RES_ERR;
	}

	return SCPI_RES_OK;
}

// Function to control all lights simultaneously
static scpi_result_t LIGHT_All(scpi_t * context) {
	scpi_bool_t allOn;
	XMC_DEBUG("## LIGHT_All\r\n");

	if (!SCPI_ParamBool(context, &allOn, TRUE)) {
		SCPI_ResultBool(context, FALSE);
		return SCPI_RES_ERR;
	}

	if (allOn) { XMC_DEBUG(" - ALL LIGHTS ON\r\n"); }
	else { XMC_DEBUG(" - ALL LIGHTS OFF\r\n"); }

	// Loop through all channels to set their states
	for (int i = 0; i < NUM_CHANNELS; i++) {
		setChannelState(i, allOn, 0);
	}

	SCPI_ResultBool(context, TRUE);
	return SCPI_RES_OK;
}

// Function to dim all lights
static scpi_result_t DIM_All(scpi_t * context) {
    float percentage = 0;
    XMC_DEBUG("## DIM_All\r\n");

    if (zcdLastCount <= 0 || !SCPI_ParamFloat(context, &percentage, TRUE)) {
		SCPI_ResultBool(context, FALSE);
		return SCPI_RES_ERR;
	}

	XMC_DEBUG(" - Dimming %f\r\n", percentage);

	int dimmingVal = calculateDimming(percentage);

	// Loop through all channels to set their states
	for (int i = 0; i < 18; i++) {
		int state = (dimmingVal == 10000) ? 1 : 0;
		setChannelState(i, state, dimmingVal);
	}

	SCPI_ResultBool(context, TRUE);
	return SCPI_RES_OK;
}

static scpi_result_t LIGHT_Ch(scpi_t * context) {
	scpi_bool_t state;
	int32_t ch;

	if (!SCPI_CommandNumbers(context, &ch, 1, 1) || ch < 1 || ch > NUM_CHANNELS) {
		SCPI_ResultBool(context, FALSE);
		return SCPI_RES_ERR;
	}

	if (!SCPI_ParamBool(context, &state, TRUE)) {
		SCPI_ResultBool(context, FALSE);
		return SCPI_RES_ERR;
	}

	XMC_DEBUG("## LIGHT_Ch %ld\r\n", ch);

	setChannelState(ch - 1, state, 0); // Control individual channel

	SCPI_ResultBool(context, TRUE);
	return SCPI_RES_OK;
}

static scpi_result_t DIM_Ch(scpi_t * context) {
	float percentage;
	int32_t ch;

	if (!SCPI_CommandNumbers(context, &ch, 1, 1) || ch < 1 || ch > NUM_CHANNELS) {
		SCPI_ResultBool(context, FALSE);
		return SCPI_RES_ERR;
	}

	if (!SCPI_ParamFloat(context, &percentage, TRUE) || zcdLastCount <= 0) {
		SCPI_ResultBool(context, FALSE);
		return SCPI_RES_ERR;
	}

	XMC_DEBUG(" DIM_Ch %ld - Dimming %f\r\n", ch, percentage);

	int dimmingVal = calculateDimming(percentage);

	int state = (dimmingVal == 10000) ? 1 : 0;
	setChannelState(ch - 1, state, dimmingVal);

	SCPI_ResultBool(context, TRUE);
	return SCPI_RES_OK;
}



/**
 * Re-implement IEEE488.2 *TST?
 *
 * Result should be 0 if everything is ok
 * Result should be 1 if something goes wrong
 *
 * Return SCPI_RES_OK
 */
static scpi_result_t My_CoreTstQ(scpi_t * context) {

    SCPI_ResultInt32(context, 0);

    return SCPI_RES_OK;
}

const scpi_command_t scpi_commands[] = {
    /* IEEE Mandated Commands (SCPI std V1999.0 4.1.1) */
    { .pattern = "*CLS", .callback = SCPI_CoreCls,},
    { .pattern = "*ESE", .callback = SCPI_CoreEse,},
    { .pattern = "*ESE?", .callback = SCPI_CoreEseQ,},
    { .pattern = "*ESR?", .callback = SCPI_CoreEsrQ,},
    { .pattern = "*IDN?", .callback = SCPI_CoreIdnQ,},
    { .pattern = "*OPC", .callback = SCPI_CoreOpc,},
    { .pattern = "*OPC?", .callback = SCPI_CoreOpcQ,},
    { .pattern = "*RST", .callback = SCPI_CoreRst,},
    { .pattern = "*SRE", .callback = SCPI_CoreSre,},
    { .pattern = "*SRE?", .callback = SCPI_CoreSreQ,},
    { .pattern = "*STB?", .callback = SCPI_CoreStbQ,},
    { .pattern = "*TST?", .callback = My_CoreTstQ,},
    { .pattern = "*WAI", .callback = SCPI_CoreWai,},

    /* Required SCPI commands (SCPI std V1999.0 4.2.1) */
    {.pattern = "SYSTem:ERRor[:NEXT]?", .callback = SCPI_SystemErrorNextQ,},
    {.pattern = "SYSTem:ERRor:COUNt?", .callback = SCPI_SystemErrorCountQ,},
    {.pattern = "SYSTem:VERSion?", .callback = SCPI_SystemVersionQ,},

    /* {.pattern = "STATus:OPERation?", .callback = scpi_stub_callback,}, */
    /* {.pattern = "STATus:OPERation:EVENt?", .callback = scpi_stub_callback,}, */
    /* {.pattern = "STATus:OPERation:CONDition?", .callback = scpi_stub_callback,}, */
    /* {.pattern = "STATus:OPERation:ENABle", .callback = scpi_stub_callback,}, */
    /* {.pattern = "STATus:OPERation:ENABle?", .callback = scpi_stub_callback,}, */

    {.pattern = "STATus:QUEStionable[:EVENt]?", .callback = SCPI_StatusQuestionableEventQ,},
    /* {.pattern = "STATus:QUEStionable:CONDition?", .callback = scpi_stub_callback,}, */
    {.pattern = "STATus:QUEStionable:ENABle", .callback = SCPI_StatusQuestionableEnable,},
    {.pattern = "STATus:QUEStionable:ENABle?", .callback = SCPI_StatusQuestionableEnableQ,},

    {.pattern = "STATus:PRESet", .callback = SCPI_StatusPreset,},

	{.pattern = "INPut[:BUTTON1]?", .callback = IO_Btn,},
	{.pattern = "OUTPut[:LED1]", .callback = IO_Led,},

	{.pattern = "ZCD[:VALue]?", .callback = ZCD_ValueQuery,},

#ifdef XMC_DEBUG_ENABLE
	{.pattern = "ZCD[:VALue]", .callback = ZCD_ValueSet,},
#endif

	{.pattern = "CSense?", .callback = CurrentSense_Query,},

	{.pattern = "LIGHTs[:ALL]", .callback = LIGHT_All,},
	{.pattern = "LIGHTs:CH#", .callback = LIGHT_Ch,},
	{.pattern = "DIMmer[:ALL]", .callback = DIM_All,},
	{.pattern = "DIMmer:CH#", .callback = DIM_Ch,},
//    {.pattern = "SYSTem:COMMunication:TCPIP:CONTROL?", .callback = SCPI_SystemCommTcpipControlQ,},


    SCPI_CMD_LIST_END
};

scpi_interface_t scpi_interface = {
    .error = SCPI_Error,
    .write = SCPI_Write,
    .control = SCPI_Control,
    .flush = SCPI_Flush,
    .reset = SCPI_Reset,
};

char scpi_input_buffer[SCPI_INPUT_BUFFER_LENGTH];
scpi_error_t scpi_error_queue_data[SCPI_ERROR_QUEUE_SIZE];

scpi_t scpi_context;

