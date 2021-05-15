
/*
 * NVIC_PRIVATE
 *
 * Created: 9/20/2019 2:04:42 PM
 * Author: Mahmoud Amr
 * Version: V01
 */ 


#ifndef NVIC_PRIVATE_H_
#define NVIC_PRIVATE_H_


/*			NVIC Address 0xE000E100		*/

#define NVIC			0xE000E100

#define NVIC_ISER0 		*((u32*) (NVIC + 0x00))			// Enable external in 0 to 31
#define NVIC_ISER1 		*((u32*) (NVIC + 0x04))			// Enable external in 31 to 63
#define NVIC_ISER2 		*((u32*) (NVIC + 0x08))			// Enable external in 64 to

#define NVIC_ICER0 		*((u32*) (NVIC + 0x080))		// disable external in 0 to 31
#define NVIC_ICER1 		*((u32*) (NVIC + 0x084))		// disable external in 31 to 63
#define NVIC_ICER2 		*((u32*) (NVIC + 0x088))		// disable external in 64 to

#define NVIC_ISPR0 		*((u32*) (NVIC + 0x100))		// disable external in 0 to 31
#define NVIC_ISPR1 		*((u32*) (NVIC + 0x104))		// disable external in 31 to 63
#define NVIC_ISPR2 		*((u32*) (NVIC + 0x108))		// disable external in 64 to

#define NVIC_ICPR0 		*((u32*) (NVIC + 0x180))		// disable external in 0 to 31
#define NVIC_ICPR1 		*((u32*) (NVIC + 0x184))		// disable external in 31 to 63
#define NVIC_ICPR2 		*((u32*) (NVIC + 0x188))		// disable external in 64 to

#define NVIC_IABR0 		*((volatile u32*) (NVIC + 0x200))		// disable external in 0 to 31
#define NVIC_IABR1 		*((volatile u32*) (NVIC + 0x204))		// disable external in 31 to 63
#define NVIC_IABR2 		*((volatile u32*) (NVIC + 0x208))		// disable external in 64 to

#define NVIC_IPR		((volatile u8*)(0xE000E100 + 0x300 ))
#define SCB_AIRCR		*((volatile u32*) (0xE000ED00 + 0x0C ))



#endif /* NVIC_PRIVATE_H_ */
