/*
 * BIT_MATH.h
 *
 * Created: 9/20/2019 2:04:42 PM
 *  Author: Mahmoud Amr
 *  Version V_2
 */


#ifndef BIT_MATH_H_
#define BIT_MATH_H_

//************* Std_macros.h ***************************



#define CLR_BIT(PORT,bit) 	PORT &= (~(1<<bit))
#define SET_BIT(PORT,bit) 	PORT |= (1<<bit)
#define TOG_BIT(PORT,bit)	PORT ^= (1<<bit) //TOGGLE_BIT
#define GET_BIT(PORT,bit) 	((PORT>>bit) & 1)



#define is_bit_set(Port,bit) 	(Port&(1<<bit))>>bit
#define is_bit_clr(Port,bit) 	!(Port&(1<<bit))>>bit
#define ror(Port,num) 		Port=(Port<<(Register_size - num ))|(Port>>(num))
#define rol(Port,num) 		Port=(Port>>(Register_size - num ))|(Port>>(num))
//********************************************************

#endif /* BIT_MATH_H_ */
