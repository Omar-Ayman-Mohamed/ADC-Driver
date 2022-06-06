/*
 * adc.h
 *
 *  Created on: Jun 1, 2022
 *      Author: wario
 */

#ifndef INC_ADC_H_
#define INC_ADC_H_
#define Use_Polling 1
enum resultion{res12 ,res10,res8,res6};
enum Conversion_mode{single,continous};
void ADC_StartConv(unsigned char ChannelNum);

void ADC_GetConversionState(unsigned char* ConversionStatePtr);
unsigned char ADC_ReadData(unsigned short int* DataPtr);
typedef struct mystruct{
	enum resultion res;
	enum Conversion_mode conv;
	int vref;
}ADCConfigType;
void ADC_Init(ADCConfigType* ConfigParamPtr);
#endif /* INC_ADC_H_ */
