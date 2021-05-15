
/*
 * EXTI_PRIVATE
 *
 * Created: 9/20/2019 2:04:42 PM
 * Author: Mahmoud Amr
 * Version: V01
 */ 


#ifndef EXTI_PRIVATE_H_
#define EXTI_PRIVATE_H_

typedef struct{
	u32 IMR;
	u32 EMR;
	u32 RTSR;
	u32 FTSR;
	u32 SWIER;
	u32 PR;


}EXTI_t;

#define EXTI		((volatile EXTI_t* )0x40010400)

#define LINE0  		0
#define LINE1  		1
#define LINE2  		2
#define LINE3  		3
#define LINE4  		4
#define LINE5  		5
#define LINE6  		6
#define LINE7  		7
#define LINE8  		8
#define LINE9  		9
#define LINE10  	10
#define LINE11 		11
#define LINE12  	12
#define LINE13      13
#define LINE14	    14
#define LINE15		15


#define RISING		0
#define FALLING		1
#define ON_CHANGE	2

#endif /* EXTI_PRIVATE_H_ */
