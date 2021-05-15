/*
 * ADC_private.h
 *
 *  Created on: May 10, 2021
 *      Author: Mahmoud Amr
 */

#ifndef INCLUDE_ADC_PRIVATE_H_
#define INCLUDE_ADC_PRIVATE_H_




		//		ADC Ptivate



//------------ RCC IP--------------------

#define ADC1EN_IP	9
#define ADC2EN_IP	10
#define ADC3EN_IP	15

/*!< ADCPPRE configuration */
#define  RCC_CFGR_ADCPRE                     ((uint32_t)0x0000C000)        /*!< ADCPRE[1:0] bits (ADC prescaler) */
#define  RCC_CFGR_ADCPRE_0                   ((uint32_t)0x00004000)        /*!< Bit 0 */
#define  RCC_CFGR_ADCPRE_1                   ((uint32_t)0x00008000)        /*!< Bit 1 */



#define RCC_CFGR       *((u32*)0x40021004)

//---------------------------------------------------------------------------------

#define ADC1		0x40012400
#define ADC2		0x40012800
#define ADC3		0x40013C00


/* Register Definitions */

#define ADC_SR		*((u32*) (ADC1 + 0x00))
#define ADC_CR1 	*((u32*) (ADC1 + 0x04))
#define ADC_CR2		*((u32*) (ADC1 + 0x08))
#define ADC_SMPR1	*((u32*) (ADC1 + 0x0C))
#define ADC_SMPR2	*((u32*) (ADC1 + 0x10))
#define ADC_JOFR1	*((u32*) (ADC1 + 0x14))
#define ADC_JOFR2	*((u32*) (ADC1 + 0x18))
#define ADC_JOFR3	*((u32*) (ADC1 + 0x1C))
#define ADC_JOFR4 	*((u32*) (ADC1 + 0x20))
#define ADC_HTR		*((u32*) (ADC1 + 0x24))
#define ADC_LTR		*((u32*) (ADC1 + 0x28))
#define ADC_SQR1	*((u32*) (ADC1 + 0x2C))
#define ADC_SQR2	*((u32*) (ADC1 + 0x30))
#define ADC_SQR3	*((u32*) (ADC1 + 0x34))
#define ADC_JSQR	*((u32*) (ADC1 + 0x38))
#define ADC_JDR1 	*((u32*) (ADC1 + 0x3C))
#define ADC_JDR2	*((u32*) (ADC1 + 0x40))
#define ADC_JDR3	*((u32*) (ADC1 + 0x44))
#define ADC_JDR4	*((u32*) (ADC1 + 0x48))
#define ADC_DR		*((u32*) (ADC1 + 0x4C))








//			ADC control register 2 (ADC_CR2)

#define ADON			0
#define CONT			1
#define CAL				2
#define RSTCAL			3
#define JSWSTART		21
#define ALIGN			11









/**  defgroup ADC_mode
  */

#define ADC_Mode_Independent                       ((uint32_t)0x00000000)
#define ADC_Mode_RegInjecSimult                    ((uint32_t)0x00010000)
#define ADC_Mode_RegSimult_AlterTrig               ((uint32_t)0x00020000)
#define ADC_Mode_InjecSimult_FastInterl            ((uint32_t)0x00030000)
#define ADC_Mode_InjecSimult_SlowInterl            ((uint32_t)0x00040000)
#define ADC_Mode_InjecSimult                       ((uint32_t)0x00050000)
#define ADC_Mode_RegSimult                         ((uint32_t)0x00060000)
#define ADC_Mode_FastInterl                        ((uint32_t)0x00070000)
#define ADC_Mode_SlowInterl                        ((uint32_t)0x00080000)
#define ADC_Mode_AlterTrig                         ((uint32_t)0x00090000)




/** defgroup ADC_data_align
  */

#define ADC_DataAlign_Right                        ((uint32_t)0x00000000)
#define ADC_DataAlign_Left                         ((uint32_t)0x00000800)




/** @defgroup ADC_channels
  * @{
  */

#define ADC_Channel_0                               ((uint8_t)0x00)
#define ADC_Channel_1                               ((uint8_t)0x01)
#define ADC_Channel_2                               ((uint8_t)0x02)
#define ADC_Channel_3                               ((uint8_t)0x03)
#define ADC_Channel_4                               ((uint8_t)0x04)
#define ADC_Channel_5                               ((uint8_t)0x05)
#define ADC_Channel_6                               ((uint8_t)0x06)
#define ADC_Channel_7                               ((uint8_t)0x07)
#define ADC_Channel_8                               ((uint8_t)0x08)
#define ADC_Channel_9                               ((uint8_t)0x09)
#define ADC_Channel_10                              ((uint8_t)0x0A)
#define ADC_Channel_11                              ((uint8_t)0x0B)
#define ADC_Channel_12                              ((uint8_t)0x0C)
#define ADC_Channel_13                              ((uint8_t)0x0D)
#define ADC_Channel_14                              ((uint8_t)0x0E)
#define ADC_Channel_15                              ((uint8_t)0x0F)
#define ADC_Channel_16                              ((uint8_t)0x10)
#define ADC_Channel_17                              ((uint8_t)0x11)

#define ADC_Channel_TempSensor                      ((uint8_t)ADC_Channel_16)
#define ADC_Channel_Vrefint                         ((uint8_t)ADC_Channel_17)





/**  def group ADC_sampling_time
  */

#define ADC_SampleTime_1_5_CYCLES                    ((uint8_t)0x00)
#define ADC_SampleTime_7_5_CYCLES                    ((uint8_t)0x01)
#define ADC_SampleTime_13_5_CYCLES                   ((uint8_t)0x02)
#define ADC_SampleTime_28_5_CYCLES                   ((uint8_t)0x03)
#define ADC_SampleTime_41_5_CYCLES                   ((uint8_t)0x04)
#define ADC_SampleTime_55_5_CYCLES                   ((uint8_t)0x05)
#define ADC_SampleTime_71_5_CYCLES                   ((uint8_t)0x06)
#define ADC_SampleTime_239_5_CYCLES                  ((uint8_t)0x07)







#endif /* INCLUDE_ADC_PRIVATE_H_ */
