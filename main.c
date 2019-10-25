/*  Led açip kapatma uygulamasi dogrudan registerler kodlanarak yapildi
		Registerlere ilgili bitin durumunu girmek için bit islemleri kullanilir
		&(ve), |(veya) , ~(degili), ^(XOR),  <<(sola kaydir),  >>(saga kaydir) baslica bit islem sembolleridir
		
		Blink application directly done by coding register
		Bit operations are used to enter the state of the corresponding bit
		&(and), |(or) , ~(Bitwise complement), ^(XOR), <<(shift left), >>(shift right) are primary bit operation symbols
		
		 	p   q   p&q   p|q   ~(p&q)   p^q
			0   0    0     0       1      0
			1   0    0     1       1      1
			0   1    0     1       1      1
			1   1    1     1       0      0
*/
#include "stm32f4xx.h"                  // Device header
                     

int main(void)
{
	// Enable the GPIO clock for port D using the AHB and RCC 	
	RCC->AHB1ENR |=RCC_AHB1ENR_GPIODEN; //0x08 OR 1<<3 its mean set the third bit 0 to 1 of the AHB1EN Register
	
	GPIOD->MODER|=GPIO_MODER_MODER12_0|GPIO_MODER_MODER13_0|GPIO_MODER_MODER14_0|GPIO_MODER_MODER15_0; // (0x55000000 for all led ,GPIO_PIN_12 TO PIN_15) 
	
	GPIOD->OTYPER &=~(GPIO_OTYPER_OT_15|GPIO_OTYPER_OT_14|GPIO_OTYPER_OT_13|GPIO_OTYPER_OT_12); //0xF000 seting output type to Push Pull
	
	GPIOD->PUPDR &= ~(GPIO_PUPDR_PUPDR15_0|GPIO_PUPDR_PUPDR14_0|GPIO_PUPDR_PUPDR13_0|GPIO_PUPDR_PUPDR12_0); // 0x55000000 for each pin setted pull down, it doesn't necessary on this project 	
	
	GPIOD->OSPEEDR |=GPIO_OSPEEDER_OSPEEDR15_1|GPIO_OSPEEDER_OSPEEDR14_1|GPIO_OSPEEDER_OSPEEDR13_1|GPIO_OSPEEDER_OSPEEDR12_1; // 0xAA000000 each pin setted high speed not VERY HIGH SPEED

	/*
	RCC->AHB1ENR|=0x08;
	GPIOD->MODER|=0x55000000;
	GPIOD->OTYPER&=~(0xF000);
	GPIOD->PUPDR&=~(0x55000000);
	GPIOD->OSPEEDR|=0xAA000000;
	*/
	
	while(1) 
	{
		// döngüye her girisinde ODR register'inin 12. 13. 14. 15. pinlerle 
		// each loop make ODR register's pins 12 13 14 and 15 to high to low and low to high (1 to 0 and after loop 0 to 1...)
		GPIOD->ODR^=1<<12;
		GPIOD->ODR^=1<<13;
		GPIOD->ODR^=1<<14;
		GPIOD->ODR^=1<<15;
		
		//delay 
	    for(int i=0;i<0xFFFFFF;i++);
	
	}
	
}


//
// CODED BY mfkutuk
//
