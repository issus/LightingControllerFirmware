
/**
 * @cond
 ***********************************************************************************************************************
 *
 * Copyright (c) 2015-2020, Infineon Technologies AG
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,are permitted provided that the
 * following conditions are met:
 *
 *   Redistributions of source code must retain the above copyright notice, this list of conditions and the  following
 *   disclaimer.
 *
 *   Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the
 *   following disclaimer in the documentation and/or other materials provided with the distribution.
 *
 *   Neither the name of the copyright holders nor the names of its contributors may be used to endorse or promote
 *   products derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES,
 * INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE  FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY,OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT  OF THE
 * USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * To improve the quality of the software, users are encouraged to share modifications, enhancements or bug fixes
 * with Infineon Technologies AG (dave@infineon.com).
 ***********************************************************************************************************************
 *
 * Change History
 * --------------
 *
 * 2014-06-16:
 *     - Initial version<br>
 * 2015-08-28:
 *     - Added CLOCK_XMC1_Init conditionally
 * 2018-08-08:
 *     - Add creation of projectData.bak file
 * 2019-01-30:
 *     - Fix creation of projectData.bak file
 * 2019-04-29:
 *     - Make DAVE_Init() weak, the user can reimplement the function
 *
 * @endcond
 *
 */

/***********************************************************************************************************************
 * HEADER FILES
 **********************************************************************************************************************/
#include "DAVE.h"

/***********************************************************************************************************************
 * API IMPLEMENTATION
 **********************************************************************************************************************/

/*******************************************************************************
 * @brief This function initializes the APPs Init Functions.
 *
 * @param[in]  None
 *
 * @return  DAVE_STATUS_t <BR>
 ******************************************************************************/
__WEAK DAVE_STATUS_t DAVE_Init(void)
{
  DAVE_STATUS_t init_status;
  
  init_status = DAVE_STATUS_SUCCESS;
     /** @Initialization of APPs Init Functions */
     init_status = (DAVE_STATUS_t)CLOCK_XMC4_Init(&CLOCK_XMC4_0);

  if (init_status == DAVE_STATUS_SUCCESS)
  {
	 /**  Initialization of ETH_LWIP APP instance ETH_LWIP_0 */
	 init_status = (DAVE_STATUS_t)ETH_LWIP_Init(&ETH_LWIP_0); 
   } 
  if (init_status == DAVE_STATUS_SUCCESS)
  {
	 /**  Initialization of DIGITAL_IO APP instance LED2 */
	 init_status = (DAVE_STATUS_t)DIGITAL_IO_Init(&LED2); 
   } 
  if (init_status == DAVE_STATUS_SUCCESS)
  {
	 /**  Initialization of DIGITAL_IO APP instance BUTTON1 */
	 init_status = (DAVE_STATUS_t)DIGITAL_IO_Init(&BUTTON1); 
   } 
  if (init_status == DAVE_STATUS_SUCCESS)
  {
	 /**  Initialization of TIMER APP instance TIMER_0 */
	 init_status = (DAVE_STATUS_t)TIMER_Init(&TIMER_0); 
   } 
  if (init_status == DAVE_STATUS_SUCCESS)
  {
	 /**  Initialization of PIN_INTERRUPT APP instance ZCD */
	 init_status = (DAVE_STATUS_t)PIN_INTERRUPT_Init(&ZCD); 
   } 
  if (init_status == DAVE_STATUS_SUCCESS)
  {
	 /**  Initialization of INTERRUPT APP instance DIMMING_INTERRUPT */
	 init_status = (DAVE_STATUS_t)INTERRUPT_Init(&DIMMING_INTERRUPT); 
   } 
  if (init_status == DAVE_STATUS_SUCCESS)
  {
	 /**  Initialization of DIGITAL_IO APP instance OUT_CH1 */
	 init_status = (DAVE_STATUS_t)DIGITAL_IO_Init(&OUT_CH1); 
   } 
  if (init_status == DAVE_STATUS_SUCCESS)
  {
	 /**  Initialization of DIGITAL_IO APP instance OUT_CH2 */
	 init_status = (DAVE_STATUS_t)DIGITAL_IO_Init(&OUT_CH2); 
   } 
  if (init_status == DAVE_STATUS_SUCCESS)
  {
	 /**  Initialization of DIGITAL_IO APP instance OUT_CH3 */
	 init_status = (DAVE_STATUS_t)DIGITAL_IO_Init(&OUT_CH3); 
   } 
  if (init_status == DAVE_STATUS_SUCCESS)
  {
	 /**  Initialization of DIGITAL_IO APP instance OUT_CH4 */
	 init_status = (DAVE_STATUS_t)DIGITAL_IO_Init(&OUT_CH4); 
   } 
  if (init_status == DAVE_STATUS_SUCCESS)
  {
	 /**  Initialization of DIGITAL_IO APP instance OUT_CH5 */
	 init_status = (DAVE_STATUS_t)DIGITAL_IO_Init(&OUT_CH5); 
   } 
  if (init_status == DAVE_STATUS_SUCCESS)
  {
	 /**  Initialization of DIGITAL_IO APP instance OUT_CH6 */
	 init_status = (DAVE_STATUS_t)DIGITAL_IO_Init(&OUT_CH6); 
   } 
  if (init_status == DAVE_STATUS_SUCCESS)
  {
	 /**  Initialization of DIGITAL_IO APP instance OUT_CH7 */
	 init_status = (DAVE_STATUS_t)DIGITAL_IO_Init(&OUT_CH7); 
   } 
  if (init_status == DAVE_STATUS_SUCCESS)
  {
	 /**  Initialization of DIGITAL_IO APP instance OUT_CH8 */
	 init_status = (DAVE_STATUS_t)DIGITAL_IO_Init(&OUT_CH8); 
   } 
  if (init_status == DAVE_STATUS_SUCCESS)
  {
	 /**  Initialization of DIGITAL_IO APP instance OUT_CH9 */
	 init_status = (DAVE_STATUS_t)DIGITAL_IO_Init(&OUT_CH9); 
   } 
  if (init_status == DAVE_STATUS_SUCCESS)
  {
	 /**  Initialization of DIGITAL_IO APP instance OUT_CH10 */
	 init_status = (DAVE_STATUS_t)DIGITAL_IO_Init(&OUT_CH10); 
   } 
  if (init_status == DAVE_STATUS_SUCCESS)
  {
	 /**  Initialization of DIGITAL_IO APP instance OUT_CH11 */
	 init_status = (DAVE_STATUS_t)DIGITAL_IO_Init(&OUT_CH11); 
   } 
  if (init_status == DAVE_STATUS_SUCCESS)
  {
	 /**  Initialization of DIGITAL_IO APP instance OUT_CH12 */
	 init_status = (DAVE_STATUS_t)DIGITAL_IO_Init(&OUT_CH12); 
   } 
  if (init_status == DAVE_STATUS_SUCCESS)
  {
	 /**  Initialization of DIGITAL_IO APP instance OUT_CH13 */
	 init_status = (DAVE_STATUS_t)DIGITAL_IO_Init(&OUT_CH13); 
   } 
  if (init_status == DAVE_STATUS_SUCCESS)
  {
	 /**  Initialization of DIGITAL_IO APP instance OUT_CH14 */
	 init_status = (DAVE_STATUS_t)DIGITAL_IO_Init(&OUT_CH14); 
   } 
  if (init_status == DAVE_STATUS_SUCCESS)
  {
	 /**  Initialization of DIGITAL_IO APP instance OUT_CH15 */
	 init_status = (DAVE_STATUS_t)DIGITAL_IO_Init(&OUT_CH15); 
   } 
  if (init_status == DAVE_STATUS_SUCCESS)
  {
	 /**  Initialization of DIGITAL_IO APP instance OUT_CH16 */
	 init_status = (DAVE_STATUS_t)DIGITAL_IO_Init(&OUT_CH16); 
   } 
  if (init_status == DAVE_STATUS_SUCCESS)
  {
	 /**  Initialization of DIGITAL_IO APP instance OUT_CH17 */
	 init_status = (DAVE_STATUS_t)DIGITAL_IO_Init(&OUT_CH17); 
   } 
  if (init_status == DAVE_STATUS_SUCCESS)
  {
	 /**  Initialization of DIGITAL_IO APP instance OUT_CH18 */
	 init_status = (DAVE_STATUS_t)DIGITAL_IO_Init(&OUT_CH18); 
   } 
  if (init_status == DAVE_STATUS_SUCCESS)
  {
	 /**  Initialization of ADC_MEASUREMENT APP instance ACCURRENT */
	 init_status = (DAVE_STATUS_t)ADC_MEASUREMENT_Init(&ACCURRENT); 
   }  
  return init_status;
} /**  End of function DAVE_Init */

