/**
 *	USART 1 example
 *
 *	@author 	Tilen Majerle
 *	@email		tilen@majerle.eu
 *	@website	http://majerle.eu
 *	@version 	v1.1
 *	@gcc		v4.7 20013qr3
 *	@ide		CooCox CoIDE v1.7.6
 */
#include "defines.h"
#include "stm32f4xx.h"
#include "tm_stm32f4_usart.h"
#include "tm_stm32f4_disco.h"


int main(void) {
	//Initialize system
	SystemInit();

	TM_DISCO_ButtonInit();

	//Initialize USART1 at 9600 baud, TX: PA9, RX: PA10
	TM_USART_Init(USART1, TM_USART_PinsPack_1, 9600);
	//Put string to terminal
	TM_USART_Puts(USART1, "Hello world\n\r");

	uint8_t c;
	while (1) {
		//Get character from internal buffer
		if (TM_DISCO_ButtonPressed()) {
			do {
				c = TM_USART_Getc(USART1);
				if (c) {
					//If anything received, put it back to terminal
					TM_USART_Putc(USART1, c);
				}
			} while (c != 0);
		}

	}
	return 0;
}