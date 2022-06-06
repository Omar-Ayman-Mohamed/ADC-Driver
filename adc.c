/*
 * adc.c
 *
 *  Created on: Jun 1, 2022
 *      Author: wario
 */


#include "stm32f4xx.h"
#include"gpio.h"
#include "adc.h"
void ADC_Init(ADCConfigType* ConfigParamPtr){

	RCC->APB2ENR |=(1u<<8);//adc clock enable
	ADC1->CR2 |=(1<<0); //adc on
	ADC->CCR &=~ADC_CCR_ADCPRE;//clock prescaler
	switch(ConfigParamPtr->res){
	case res12:
		ADC1->CR1 &=~ (1<<24);
		ADC1->CR1 &=~ (1<<25);
		break;
	case res10:
		ADC1->CR1 |= (1<<24);
		ADC1->CR1 &=~ (1<<25);
		break;
	case res8:
		ADC1->CR1 &=~ (1<<24);
		ADC1->CR1 |= (1<<25);
		break;
	case res6:
		ADC1->CR1 |= (1<<24);
		ADC1->CR1 |= (1<<25);
		break;
	}
    //conversion mode setup
    if(ConfigParamPtr->conv){
    	ADC1->CR2 |=(1<<1);//set mode continous
    }
    else{
    	ADC1->CR2 &=~(1<<1);//set mode single

    }

    if(Use_Polling){
    	ADC1->CR1&=~(1<<5);
    }
    else{
    	NVIC->ISER[0]|=(1u<<(18));
    	ADC1->CR1|=(1<<5);

    }


}
void ADC_StartConv(unsigned char ChannelNum){
	ADC1->CR2|=(1<<30);
	ADC1->SQR3 |= ChannelNum;
}
void ADC_GetConversionState(unsigned char* ConversionStatePtr){

		if(ADC1->SR & (1<<1)){
			 *ConversionStatePtr = 1 ;
		}
		else{
			*ConversionStatePtr = 0 ;
		}
	}

unsigned char ADC_ReadData(unsigned short int* DataPtr){
	unsigned char flag ;
	ADC_GetConversionState(&flag);

	if(flag){
		*DataPtr = (int)((ADC1->DR/(1.5f * 4095.0f)) * 5 * 150);
		 return 0;
	}
	else{
		return 1;
	}

}



