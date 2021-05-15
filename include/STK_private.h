/*
 * STK_private.h
 *
 *  Created on: Feb 6, 2021
 *      Author: Mahmoud Amr
 */

#ifndef INCLUDE_STK_PRIVATE_H_
#define INCLUDE_STK_PRIVATE_H_




typedef struct{
	u32 CTRL;		//SysTick control and status register (STK_CTRL)
	u32 LOAD;		//
	u32 VAL;		//
	u32 CALIB;		//
				}MSTK_t;

#define MSTK		((volatile MSTK_t* )0xE000E010)

#define     MSTK_SRC_AHB           0
#define     MSTK_SRC_AHB_8         1

#define     MSTK_SINGLE_INTERVAL    0
#define     MSTK_PERIOD_INTERVAL    1
#endif /* INCLUDE_STK_PRIVATE_H_ */
