
/*
 * AFIO_PRIVATE
 *
 * Created: 9/20/2019 2:04:42 PM
 * Author: Mahmoud Amr
 * Version: V01
 */ 


#ifndef AFIO_PRIVATE_H_
#define AFIO_PRIVATE_H_


typedef struct{

	u32 AFIO_EVCR;
	u32 AFIO_MAPR;
	u32 AFIO_EXTICR[4];
/*	u32 AFIO_EXTICR1;
	u32 AFIO_EXTICR2;
	u32 AFIO_EXTICR3;
	u32 AFIO_EXTICR4;*/
	u32 AFIO_MAPR2;

}AFIO_t;

#define AFIO	 ((volatile AIO_t*) 0x40010000)

#endif /* AFIO_PRIVATE_H_ */
