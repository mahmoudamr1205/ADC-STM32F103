
/*
 * RCC_CONFIG
 *
 * Created: 9/20/2019 2:04:42 PM
 * Author: Mahmoud Amr
 * Version: V-01
 */ 


#ifndef RCC_CONFIG_H_
#define RCC_CONFIG_H_



	/*options:  RCC_HSE_CRYSTAL
				RCC_HSE_RC
				RCC_HSI
				RCC_PLL			 */
#define RCC_CLOCK_TYPE 		RCC_HSE_CRYSTAL


		/*options:  RCC_PLL_IN_HSI_DIV_2
					RCC_PLL_IN_HSE_DIV_2
					RCC_PLL_IN_HSE		 */

		// Note: select value only if you have pll as input clock sourse
	#if RCC_CLOCK_TYPE == RCC_PLL

		#define RCC_PLL_INPUT 		RCC_PLL_IN_HSI_DIV_2
		
		// options: 2 to 16
		#define RCC_PLL_MUL_VAL 		4
		
	#endif


#endif /* RCC_CONFIG_H_ */
