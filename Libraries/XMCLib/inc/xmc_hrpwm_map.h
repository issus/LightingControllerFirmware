
/**
 * @file xmc_hrpwm_map.h
 *
 * @cond
 *****************************************************************************
 * XMClib - XMC Peripheral Driver Library
 *
 * Copyright (c) 2015-2020, Infineon Technologies AG
 * All rights reserved.
 *
 * Boost Software License - Version 1.0 - August 17th, 2003
 *
 * Permission is hereby granted, free of charge, to any person or organization
 * obtaining a copy of the software and accompanying documentation covered by
 * this license (the "Software") to use, reproduce, display, distribute,
 * execute, and transmit the Software, and to prepare derivative works of the
 * Software, and to permit third-parties to whom the Software is furnished to
 * do so, all subject to the following:
 *
 * The copyright notices in the Software and this entire statement, including
 * the above license grant, this restriction and the following disclaimer,
 * must be included in all copies of the Software, in whole or in part, and
 * all derivative works of the Software, unless such copies or derivative
 * works are solely in the form of machine-executable object code generated by
 * a source language processor.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
 * SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
 * FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
 * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 *
 * To improve the quality of the software, users are encouraged to share
 * modifications, enhancements or bug fixes with Infineon Technologies AG
 * at XMCSupport@infineon.com.
 *****************************************************************************
 *
 * @endcond
 *
 */

/**
 *
 * @brief HRPWM mapping for XMC4 microcontroller family. <br>
 *
 */

#ifndef XMC_HRPWM_MAP_H
#define XMC_HRPWM_MAP_H

#if ((UC_DEVICE == XMC4400) || (UC_DEVICE == XMC4200) || (UC_DEVICE == XMC4100))
/* CSG0 - General input to control Blanking and Switch of the Comparator */
#define XMC_HRPWM_CSG0_BL_P1_4        XMC_HRPWM_CSG_INPUT_SEL_IA
#define XMC_HRPWM_CSG0_BL_SCU_GSHR0   XMC_HRPWM_CSG_INPUT_SEL_IB
#define XMC_HRPWM_CSG0_BL_CCU80_ST0   XMC_HRPWM_CSG_INPUT_SEL_IC
#define XMC_HRPWM_CSG0_BL_CCU80_ST1   XMC_HRPWM_CSG_INPUT_SEL_ID
#define XMC_HRPWM_CSG0_BL_CCU80_ST2   XMC_HRPWM_CSG_INPUT_SEL_IE
#define XMC_HRPWM_CSG0_BL_CCU80_ST3   XMC_HRPWM_CSG_INPUT_SEL_IF
#define XMC_HRPWM_CSG0_BL_CCU40_ST0   XMC_HRPWM_CSG_INPUT_SEL_IG
#define XMC_HRPWM_CSG0_BL_CCU41_ST0   XMC_HRPWM_CSG_INPUT_SEL_IH
#define XMC_HRPWM_CSG0_BL_HRPWM_QOUT0 XMC_HRPWM_CSG_INPUT_SEL_II
#define XMC_HRPWM_CSG0_BL_HRPWM_QOUT1 XMC_HRPWM_CSG_INPUT_SEL_IJ
#define XMC_HRPWM_CSG0_BL_CCU40_SR0   XMC_HRPWM_CSG_INPUT_SEL_IK
#define XMC_HRPWM_CSG0_BL_CCU41_SR0   XMC_HRPWM_CSG_INPUT_SEL_IL
#define XMC_HRPWM_CSG0_BL_HRPWM_SR2   XMC_HRPWM_CSG_INPUT_SEL_IM
#define XMC_HRPWM_CSG0_BL_HRPWM_SR3   XMC_HRPWM_CSG_INPUT_SEL_IN
#define XMC_HRPWM_CSG0_BL_ERU1_IOUT0  XMC_HRPWM_CSG_INPUT_SEL_IO
#define XMC_HRPWM_CSG0_BL_ERU1_IOUT1  XMC_HRPWM_CSG_INPUT_SEL_IP

/* CSG0 - General input to control start/stop/trigger for Slope Control Logic */
#define XMC_HRPWM_CSG0_SC_SCU_GSHR0   XMC_HRPWM_CSG_INPUT_SEL_IB
#define XMC_HRPWM_CSG0_SC_CCU80_ST0   XMC_HRPWM_CSG_INPUT_SEL_IC
#define XMC_HRPWM_CSG0_SC_CCU80_ST1   XMC_HRPWM_CSG_INPUT_SEL_ID
#define XMC_HRPWM_CSG0_SC_CCU80_ST2   XMC_HRPWM_CSG_INPUT_SEL_IE
#define XMC_HRPWM_CSG0_SC_CCU80_ST3   XMC_HRPWM_CSG_INPUT_SEL_IF
#define XMC_HRPWM_CSG0_SC_CCU40_ST0   XMC_HRPWM_CSG_INPUT_SEL_IG
#define XMC_HRPWM_CSG0_SC_CCU41_ST0   XMC_HRPWM_CSG_INPUT_SEL_IH
#define XMC_HRPWM_CSG0_SC_HRPWM_QOUT0 XMC_HRPWM_CSG_INPUT_SEL_II
#define XMC_HRPWM_CSG0_SC_HRPWM_QOUT1 XMC_HRPWM_CSG_INPUT_SEL_IJ
#define XMC_HRPWM_CSG0_SC_CCU40_SR0   XMC_HRPWM_CSG_INPUT_SEL_IK
#define XMC_HRPWM_CSG0_SC_CCU41_SR0   XMC_HRPWM_CSG_INPUT_SEL_IL
#define XMC_HRPWM_CSG0_SC_HRPWM_C0O   XMC_HRPWM_CSG_INPUT_SEL_IM
#define XMC_HRPWM_CSG0_SC_HRPWM_SR3   XMC_HRPWM_CSG_INPUT_SEL_IN
#define XMC_HRPWM_CSG0_SC_ERU1_IOUT0  XMC_HRPWM_CSG_INPUT_SEL_IO
#define XMC_HRPWM_CSG0_SC_ERU1_IOUT1  XMC_HRPWM_CSG_INPUT_SEL_IP

/* CSG1 - General input to control Blanking and Switch of the Comparator */
#define XMC_HRPWM_CSG1_BL_P2_4        XMC_HRPWM_CSG_INPUT_SEL_IA
#define XMC_HRPWM_CSG1_BL_SCU_GSHR0   XMC_HRPWM_CSG_INPUT_SEL_IB
#define XMC_HRPWM_CSG1_BL_CCU80_ST0   XMC_HRPWM_CSG_INPUT_SEL_IC
#define XMC_HRPWM_CSG1_BL_CCU80_ST1   XMC_HRPWM_CSG_INPUT_SEL_ID
#define XMC_HRPWM_CSG1_BL_CCU80_ST2   XMC_HRPWM_CSG_INPUT_SEL_IE
#define XMC_HRPWM_CSG1_BL_CCU80_ST3   XMC_HRPWM_CSG_INPUT_SEL_IF
#define XMC_HRPWM_CSG1_BL_CCU40_ST1   XMC_HRPWM_CSG_INPUT_SEL_IG
#define XMC_HRPWM_CSG1_BL_CCU41_ST1   XMC_HRPWM_CSG_INPUT_SEL_IH
#define XMC_HRPWM_CSG1_BL_HRPWM_QOUT1 XMC_HRPWM_CSG_INPUT_SEL_II
#define XMC_HRPWM_CSG1_BL_HRPWM_QOUT2 XMC_HRPWM_CSG_INPUT_SEL_IJ
#define XMC_HRPWM_CSG1_BL_CCU40_SR1   XMC_HRPWM_CSG_INPUT_SEL_IK
#define XMC_HRPWM_CSG1_BL_CCU41_SR1   XMC_HRPWM_CSG_INPUT_SEL_IL
#define XMC_HRPWM_CSG1_BL_HRPWM_SR2   XMC_HRPWM_CSG_INPUT_SEL_IM
#define XMC_HRPWM_CSG1_BL_HRPWM_SR3   XMC_HRPWM_CSG_INPUT_SEL_IN
#define XMC_HRPWM_CSG1_BL_ERU1_IOUT0  XMC_HRPWM_CSG_INPUT_SEL_IO
#define XMC_HRPWM_CSG1_BL_ERU1_IOUT1  XMC_HRPWM_CSG_INPUT_SEL_IP

/* CSG1 - General input to control start/stop/trigger for Slope Control Logic */
#define XMC_HRPWM_CSG1_SC_SCU_GSHR0   XMC_HRPWM_CSG_INPUT_SEL_IB
#define XMC_HRPWM_CSG1_SC_CCU80_ST0   XMC_HRPWM_CSG_INPUT_SEL_IC
#define XMC_HRPWM_CSG1_SC_CCU80_ST1   XMC_HRPWM_CSG_INPUT_SEL_ID
#define XMC_HRPWM_CSG1_SC_CCU80_ST2   XMC_HRPWM_CSG_INPUT_SEL_IE
#define XMC_HRPWM_CSG1_SC_CCU80_ST3   XMC_HRPWM_CSG_INPUT_SEL_IF
#define XMC_HRPWM_CSG1_SC_CCU40_ST1   XMC_HRPWM_CSG_INPUT_SEL_IG
#define XMC_HRPWM_CSG1_SC_CCU41_ST1   XMC_HRPWM_CSG_INPUT_SEL_IH
#define XMC_HRPWM_CSG1_SC_HRPWM_QOUT1 XMC_HRPWM_CSG_INPUT_SEL_II
#define XMC_HRPWM_CSG1_SC_HRPWM_QOUT2 XMC_HRPWM_CSG_INPUT_SEL_IJ
#define XMC_HRPWM_CSG1_SC_CCU40_SR1   XMC_HRPWM_CSG_INPUT_SEL_IK
#define XMC_HRPWM_CSG1_SC_CCU41_SR1   XMC_HRPWM_CSG_INPUT_SEL_IL
#define XMC_HRPWM_CSG1_SC_HRPWM_C1O   XMC_HRPWM_CSG_INPUT_SEL_IM
#define XMC_HRPWM_CSG1_SC_HRPWM_SR3   XMC_HRPWM_CSG_INPUT_SEL_IN
#define XMC_HRPWM_CSG1_SC_ERU1_IOUT0  XMC_HRPWM_CSG_INPUT_SEL_IO
#define XMC_HRPWM_CSG1_SC_ERU1_IOUT1  XMC_HRPWM_CSG_INPUT_SEL_IP

/* CSG2 - General input to control Blanking and Switch of the Comparator */
#define XMC_HRPWM_CSG2_BL_P2_5        XMC_HRPWM_CSG_INPUT_SEL_IA
#define XMC_HRPWM_CSG2_BL_SCU_GSHR0   XMC_HRPWM_CSG_INPUT_SEL_IB
#define XMC_HRPWM_CSG2_BL_CCU80_ST0   XMC_HRPWM_CSG_INPUT_SEL_IC
#define XMC_HRPWM_CSG2_BL_CCU80_ST1   XMC_HRPWM_CSG_INPUT_SEL_ID
#define XMC_HRPWM_CSG2_BL_CCU80_ST2   XMC_HRPWM_CSG_INPUT_SEL_IE
#define XMC_HRPWM_CSG2_BL_CCU80_ST3   XMC_HRPWM_CSG_INPUT_SEL_IF
#define XMC_HRPWM_CSG2_BL_CCU40_ST2   XMC_HRPWM_CSG_INPUT_SEL_IG
#define XMC_HRPWM_CSG2_BL_CCU41_ST2   XMC_HRPWM_CSG_INPUT_SEL_IH
#define XMC_HRPWM_CSG2_BL_HRPWM_QOUT2 XMC_HRPWM_CSG_INPUT_SEL_II
#define XMC_HRPWM_CSG2_BL_HRPWM_QOUT3 XMC_HRPWM_CSG_INPUT_SEL_IJ
#define XMC_HRPWM_CSG2_BL_CCU40_SR2   XMC_HRPWM_CSG_INPUT_SEL_IK
#define XMC_HRPWM_CSG2_BL_CCU41_SR2   XMC_HRPWM_CSG_INPUT_SEL_IL
#define XMC_HRPWM_CSG2_BL_HRPWM_SR2   XMC_HRPWM_CSG_INPUT_SEL_IM
#define XMC_HRPWM_CSG2_BL_HRPWM_SR3   XMC_HRPWM_CSG_INPUT_SEL_IN
#define XMC_HRPWM_CSG2_BL_ERU1_IOUT0  XMC_HRPWM_CSG_INPUT_SEL_IO
#define XMC_HRPWM_CSG2_BL_ERU1_IOUT1  XMC_HRPWM_CSG_INPUT_SEL_IP

/* CSG2 - General input to control start/stop/trigger for Slope Control Logic */
#define XMC_HRPWM_CSG2_SC_SCU_GSHR0   XMC_HRPWM_CSG_INPUT_SEL_IB
#define XMC_HRPWM_CSG2_SC_CCU80_ST0   XMC_HRPWM_CSG_INPUT_SEL_IC
#define XMC_HRPWM_CSG2_SC_CCU80_ST1   XMC_HRPWM_CSG_INPUT_SEL_ID
#define XMC_HRPWM_CSG2_SC_CCU80_ST2   XMC_HRPWM_CSG_INPUT_SEL_IE
#define XMC_HRPWM_CSG2_SC_CCU80_ST3   XMC_HRPWM_CSG_INPUT_SEL_IF
#define XMC_HRPWM_CSG2_SC_CCU40_ST2   XMC_HRPWM_CSG_INPUT_SEL_IG
#define XMC_HRPWM_CSG2_SC_CCU41_ST2   XMC_HRPWM_CSG_INPUT_SEL_IH
#define XMC_HRPWM_CSG2_SC_HRPWM_QOUT2 XMC_HRPWM_CSG_INPUT_SEL_II
#define XMC_HRPWM_CSG2_SC_HRPWM_QOUT3 XMC_HRPWM_CSG_INPUT_SEL_IJ
#define XMC_HRPWM_CSG2_SC_CCU40_SR2   XMC_HRPWM_CSG_INPUT_SEL_IK
#define XMC_HRPWM_CSG2_SC_CCU41_SR2   XMC_HRPWM_CSG_INPUT_SEL_IL
#define XMC_HRPWM_CSG2_SC_HRPWM_C2O   XMC_HRPWM_CSG_INPUT_SEL_IM
#define XMC_HRPWM_CSG2_SC_HRPWM_SR3   XMC_HRPWM_CSG_INPUT_SEL_IN
#define XMC_HRPWM_CSG2_SC_ERU1_IOUT0  XMC_HRPWM_CSG_INPUT_SEL_IO
#define XMC_HRPWM_CSG2_SC_ERU1_IOUT1  XMC_HRPWM_CSG_INPUT_SEL_IP

#endif

#endif  /* XMC_HRPWM_MAP_H */
