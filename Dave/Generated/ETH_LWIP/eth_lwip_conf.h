/*********************************************************************************************************************
* DAVE APP Name : ETH_LWIP       APP Version: 4.1.18
*
* NOTE:
* This file is generated by DAVE. Any manual modification done to this file will be lost when the code is regenerated.
*********************************************************************************************************************/

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
 * 2016-01-14:
 *     - Initial version for DAVEv4.
 *
 * 2018-10-11:
 *     - Fix include path for autoip.h
 *
 * @endcond
 *
 */
#ifndef ETH_LWIP_CONF_H
#define ETH_LWIP_CONF_H
/***********************************************************************************************************************
 * HEADER FILES
 **********************************************************************************************************************/


#define ETH_LWIP_MAJOR_VERSION (4U)
#define ETH_LWIP_MINOR_VERSION (1U)
#define ETH_LWIP_PATCH_VERSION (18U)

/*PHY identifiers*/
#define PHY_USER_DEFINED (0U)
#define PHY_KSZ8081RNB	 (1U)
#define PHY_KSZ8031RNL   (2U)
#define PHY_DP83848C  	 (3U)

#include "ETH_LWIP/lwip/include/lwip/opt.h"

#include "SYSTIMER/systimer.h"
#include "ETH_LWIP/lwip/include/lwip/timeouts.h"
#include "ETH_LWIP/lwip/include/lwip/init.h"

#ifndef PHY_DEVICE_NAME

#define PHY_DEVICE_NAME  PHY_KSZ8081RNB 
#endif

/*IPv4 address*/
/*Static IPv4 address*/
#define IP_ADDR0 (10U)
#define IP_ADDR1 (0U)
#define IP_ADDR2 (0U)
#define IP_ADDR3 (100U)

/*IPv4 subnet mask*/
/*Static IPv4 address*/
#define NETMASK_ADDR0 (255U)
#define NETMASK_ADDR1 (255U)
#define NETMASK_ADDR2 (255U)
#define NETMASK_ADDR3 (0U)

/*IPv4 gateway address*/
/*Static IPv4 address*/
#define GW_ADDR0 (10U)
#define GW_ADDR1 (0U)
#define GW_ADDR2 (0U)
#define GW_ADDR3 (1U)

#define ETH_SYSTIMER_NAME  SYSTIMER_0

#define ETH_BROADCAST_EN  1
#define ETH_TIME_250ms_COUNT  (250U * 1000U)

#endif
