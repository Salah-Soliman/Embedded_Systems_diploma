/*
 * fifo.h
 *
 *  Created on: Nov 11, 2023
 *      Author: Salah Soliman
 */

#ifndef FIFO_H_
#define FIFO_H_

#include "stdio.h"
#include "Platform_Types.h"

//USER Configuration
//Select the element type (uint8_t , uint16_t , uint32_t , ......)
#define element_type uint8_t
//Create buffer 1
#define width1 5
element_type uart_buf[width1] ;

//FIFO data types

typedef struct {
	unsigned int length ;
	unsigned int count ;
	element_type* base ;
	element_type* head ;
	element_type* tail ;
}FIFO_Buf_t ;

typedef enum {
	FIFO_no_error ,
	FIFO_full ,
	FIFO_empty ,
	FIFO_null
}FIFO_Buf_Status;

//FIFO APIs

FIFO_Buf_Status FIFIO_init(FIFO_Buf_t* fifo,element_type* buf, unsigned int length);
FIFO_Buf_Status FIFIO_enqueue(FIFO_Buf_t* fifo, element_type item);
FIFO_Buf_Status FIFIO_dequeue(FIFO_Buf_t* fifo, element_type* item);
FIFO_Buf_Status FIFIO_IS_FULL(FIFO_Buf_t* fifo);
void FIFIO_print (FIFO_Buf_t* fifo);






#endif /* FIFO_H_ */
