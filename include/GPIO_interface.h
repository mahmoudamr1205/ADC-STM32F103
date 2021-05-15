
/*
 * GPIO_INTERFACE
 *
 * Created: 9/20/2019 2:04:42 PM
 * Author: Mahmoud Amr
 * Version: V01
 */ 


#ifndef GPIO_INTERFACE_H_
#define GPIO_INTERFACE_H_


//------------ RCC IP--------------------

#define GPIOA_IP	2
#define	GPIOB_IP	3
#define	GPIOC_IP	4

//-------------------- Macros ---------------------------------------
#define GPIOA   1
#define GPIOB   2
#define GPIOC	3


#define PIN0 	0
#define PIN1	1
#define PIN2	2
#define PIN3	3
#define PIN4	4
#define PIN5	5
#define PIN6	6
#define PIN7	7
#define PIN8	8
#define PIN9	9
#define PIN10	10
#define PIN11	11
#define PIN12	12
#define PIN13	13
#define PIN14	14
#define PIN15	15

//------------------------------------------------------------
#define	LOW  0
#define HIGH 1
//-----------------------Modes-------------------------------

//For Speed 10
#define OUTPUT_SPEED_10MHZ_PP     0b0001
#define OUTPUT_SPEED_10MHZ_OD     0b0101
#define OUTPUT_SPEED_10MHZ_AFPP   0b1001
#define OUTPUT_SPEED_10MHZ_AFOD   0b1101

//For Speed 2
#define OUTPUT_SPEED_2MHZ_PP      0b0010
#define OUTPUT_SPEED_2MHZ_OD      0b0110
#define OUTPUT_SPEED_2MHZ_AFPP    0b1010
#define OUTPUT_SPEED_2MHZ_AFOD    0b1110

//For Speed 50
#define OUTPUT_SPEED_50MHZ_PP     0b0011
#define OUTPUT_SPEED_50MHZ_OD     0b0111
#define OUTPUT_SPEED_50MHZ_AFPP   0b1011
#define OUTPUT_SPEED_50MHZ_AFOD   0b1111

// INPUT
#define INPUT_ANLOG               0b0000
#define INPUT_FLOATING            0b0100
#define INPUT_PULLUP_PULLDOWN     0b1000

/*
#define Input_floating 					0
#define Input_pullup 					1
#define Input_pulldown					2
#define Analog							3
#define Output_open_drain				4
#define Output_push_pull				5
#define Alternate_function_push_pull	 6
#define Alternate_function_open_drain	 7
*/
//------------------------------------------------------------


/* PORT: GPIOA -GPIOB - GPIOC
 * PIN:  PIN0 - PIN1 - PIN2 ..... PIN15
 * Value: LOW  - HIGH
 * MODE: INPUT - OUTPUT					*/
void MGPIO_VoidSetPinDirection(u8 copy_u8PORT, u8 copy_u8PIN, u8 copy_u8MODE);


/* PORT: GPIOA -GPIOB - GPIOC
 * PIN:  PIN0 - PIN1 - PIN2 ..... PIN15
 * Value: LOW  - HIGH
 * MODE: INPUT - OUTPUT					*/
void MGPIO_VoidSetPinValue(u8 copy_u8PORT, u8 copy_u8PIN, u8 copy_u8VALUE);

/* PORT: GPIOA -GPIOB - GPIOC
 * PIN:  PIN0 - PIN1 - PIN2 ..... PIN15
 * Value: LOW  - HIGH
 * MODE: INPUT - OUTPUT					*/
u8 MGPIO_u8GetPinValue(u8 copy_u8PORT, u8 copy_u8PIN);


#endif /* GPIO_INTERFACE_H_ */
