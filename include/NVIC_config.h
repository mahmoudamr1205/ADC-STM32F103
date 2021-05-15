
/*
 * NVIC_CONFIG
 *
 * Created: 29/8/2019 2:04:42 PM
 * Author: Mahmoud Amr
 * Version: V01
 */ 


#ifndef NVIC_CONFIG_H_
#define NVIC_CONFIG_H_


	/*
	 *  MNVIC_GROUP_4_SUB_0			0X05FA0300		// 4 bit for group priority - 0 bit for sub priority  in IPR
		MNVIC_GROUP_3_SUB_1			0X05FA0400		// 3 bit for group priority - 1 bit for sub priority  in IPR
		MNVIC_GROUP_2_SUB_2			0X05FA0500		// 2 bit for group priority - 2 bit for sub priority  in IPR
		MNVIC_GROUP_1_SUB_3			0X05FA0600		// 1 bit for group priority - 3 bit for sub priority
		MNVIC_GROUP_0_SUB_4			0X05FA0700		// 0 bit for group priority - 4 bit for sub priority
	 *
	 */
	

#define MNVIC_GROUP_SUB_DISTRIBUTION 		MNVIC_GROUP_2_SUB_2



#endif /* NVIC_CONFIG_H_ */
