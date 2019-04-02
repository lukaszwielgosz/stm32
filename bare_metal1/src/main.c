#include "stm32f1xx.h"

//extern void initialise_monitor_handles(void);

int main(void){
//	initialise_monitor_handles();

	uint32_t a;

	a = 2;
	//printf(msg);


	RCC->APB2ENR |= (1 << 3) | (1 << 4);

	a = 1024;
	GPIOC->CRH |= (1 << 21);
	GPIOC->CRH &= ~(0x11 << 22);

	GPIOC->CRH |= (1 << 29);
	GPIOC->CRH &= ~(0x11 << 30);

	a = 4;
	GPIOB->CRL &= ~(1<< 26);
	GPIOB->CRL |= (1<< 27);
	GPIOB->ODR |= (1<< 6);


	//GPIOC->ODR |= (1U << 13);
	//GPIOC->ODR ^= (1U << 13);

	uint32_t *GPIOC_ODR = 0x0;
	GPIOC_ODR = 0x40011000 + 0x0C;

	*GPIOC_ODR = *GPIOC_ODR | 0x8000;
	*GPIOC_ODR = *GPIOC_ODR & ~(0x8000);



	while(1){

		if(GPIOB->IDR & 0x40){
			GPIOC->BSRR = (1 << 13) | (1 << 15);
		}
		else{
			GPIOC->BRR = (1 << 13) | (1 << 15);
		}


	}
}
