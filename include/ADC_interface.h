/*
 * ADC_interface.h
 *
 *  Created on: May 10, 2021
 *      Author: Mahmoud Amr
 */

#ifndef INCLUDE_ADC_INTERFACE_H_
#define INCLUDE_ADC_INTERFACE_H_



#define  RCC_CFGR_ADCPRE_DIV2                1        /*!< PCLK2 divided by 2 */
#define  RCC_CFGR_ADCPRE_DIV4                2        /*!< PCLK2 divided by 4 */
#define  RCC_CFGR_ADCPRE_DIV6                3        /*!< PCLK2 divided by 6 */
#define  RCC_CFGR_ADCPRE_DIV8                4        /*!< PCLK2 divided by 8 */




/*
 * ADC_program.c
 *
 *  Created on: May 9, 2021
 *      Author: Mahmoud Amr
 */


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "ADC_interface.h"
#include "ADC_config.h"
#include "ADC_private.h"


#include "RCC_interface.h"
#include "GPIO_interface.h"



void MADC_VoidInit(void);
void MADC_VoidSet_Clock(u8 copy_u8ADCPRE);


void MADC_VoidSetPinMode(u8 copy_u8PORT, u8 copy_u8PIN);


u16 ReadAnalog(void);


#endif /* INCLUDE_ADC_INTERFACE_H_ */
