/*
 * LCD2004_config.h
 *
 *  Created on: May 8, 2021
 *      Author: Mahmoud Amr
 */

#ifndef INCLUDE_LCD2004_CONFIG_H_
#define INCLUDE_LCD2004_CONFIG_H_




//		---------------------------Configuration START -----------------------------

//#define four_bits_mode
//#define eight_bits_mode

#define four_bits_mode	//four_bits_mode

#ifdef  four_bits_mode

#define RS 			PIN10
#define EN 			PIN11
#define D4			PIN12
#define D5			PIN13
#define D6			PIN14
#define D7			PIN15

#define LCD_PORT	GPIOB

#endif

#ifdef eight_bits_mode


#endif




//		---------------------------Configuration end -----------------------------



#endif /* INCLUDE_LCD2004_CONFIG_H_ */
