/*
 * fifo.c
 *
 *  Created on: Nov 11, 2023
 *      Author: Salah Soliman
 */

#include "fifo.h"

//FIFO APIs

FIFO_Buf_Status FIFIO_init(FIFO_Buf_t* fifo,element_type* buf, unsigned int length)
{
	if (buf == NULL)
		return FIFO_null ;

	fifo->base = buf ;
	fifo->head = buf ;
	fifo->tail = buf ;
	fifo->length = length ;
	fifo->count = 0 ;
	return FIFO_no_error ;
}


FIFO_Buf_Status FIFIO_enqueue(FIFO_Buf_t* fifo, element_type item)
{
	if (!fifo->base || !fifo->head || !fifo->tail )
		return FIFO_null ;

	if (FIFIO_IS_FULL(fifo)== FIFO_full)
		return FIFO_full ;

	*(fifo->head) = item ;
	fifo->count++;
	//circular fifo
	if( fifo->head == (fifo->base + (fifo->length * sizeof(element_type))))
		fifo->head = fifo->base ;
	else
		fifo->head++;

	return FIFO_no_error ;
}

FIFO_Buf_Status FIFIO_IS_FULL(FIFO_Buf_t* fifo)
{
	if (!fifo->base || !fifo->head || !fifo->tail )
		return FIFO_null ;

	if (fifo->count == fifo->length)
		return FIFO_full ;
	return FIFO_no_error ;
}


FIFO_Buf_Status FIFIO_dequeue(FIFO_Buf_t* fifo, element_type* item)
{
	if (!fifo->base || !fifo->head || !fifo->tail )
		return FIFO_null ;

	if (fifo->count == 0)  //check if the fifo is empty
		return FIFO_empty ;

	*item = *(fifo->tail) ;
	fifo->count -- ;
	//circular fifo
	if( fifo->tail == (fifo->base + (fifo->length * sizeof(element_type))))
		fifo->tail = fifo->base ;
	else
		fifo->tail++;

	return FIFO_no_error ;

}

void FIFIO_print (FIFO_Buf_t* fifo)
{
	element_type* temp = 0 ;
	int i ;

	if (fifo->count == 0)
		printf("fifo is empty");
	else
	{
		temp = fifo->tail ;
		printf("=========fifo_print=========\n");
		for (i=0;i<fifo->count;i++)
		{
			printf("\t %X \n",*temp);
			temp++;
		}
		printf("==================\n");
	}
}

