/*
 * main.c
 *
 *  Created on: Nov 11, 2023
 *      Author: Salah Soliman
 */


#include "fifo.h"


int main(){
	FIFO_Buf_t FIFO_UART ;
	element_type i , temp = 0;

	if (FIFIO_init(&FIFO_UART , uart_buf, 5) == FIFO_no_error)
		printf("fifo init.....successful\n");

	for (i=0 ; i<7 ; i++)
	{
		printf("FIFO Enqueue (%x) \n",i);
		if (FIFIO_enqueue(&FIFO_UART , i) == FIFO_no_error)
			printf("\t fifo enqueue.....successful \n");
		else
			printf("\t fifo enqueue.....failed \n") ;
	}

	FIFIO_print(&FIFO_UART);
	if (FIFIO_dequeue(&FIFO_UART, &temp) == FIFO_no_error)
		printf("fifo dequeue %X.....successful \n",temp);
	if (FIFIO_dequeue(&FIFO_UART, &temp) == FIFO_no_error)
		printf("fifo dequeue %X.....successful \n",temp);
	FIFIO_print(&FIFO_UART);

}
