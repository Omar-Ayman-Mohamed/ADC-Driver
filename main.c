#include "stm32f4xx.h"
#include"adc.h"
#include"LCD.h"
#include"gpio.h"
unsigned short int data  ;
void single_mode(void);


int main(void)
{
	for(int i =0;i<=5000000;i++);
	//        initialization
	// Enable clock to GPIOA
	RCC->AHB1ENR |=(1u<<0);
	ADCConfigType  adc;


	// pin 1 to analog mmode
	GPIOA->MODER |= (1u<<0);
	GPIOA->MODER |= (1u<<1);
	GPIOA->PUPDR &=~(1u<<0);
	GPIOA->PUPDR &=~(1u<<1);

	adc.res = res12;
	adc.conv = continous;
	adc.vref = 1.5;
	LCD_Init();
	ADC_Init(&adc);
	ADC_StartConv(0);
	for(int i =0;i<=500000;i++);










if(Use_Polling){
	while(1)
	{
		LCD_DisplayString("temp: ");
		ADC_ReadData(&data);
		LCD_IntToStr(data);
		for(int i =0;i<=5000000;i++);
		LCD_ClearScreen();



	}
		}
}

void single_mode(void){
	LCD_DisplayString("temp: ");
	ADC_ReadData(&data);
	LCD_IntToStr(data);
}
void ADC_IRQHandler(void){
	single_mode();
}
