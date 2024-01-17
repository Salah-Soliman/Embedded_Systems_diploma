/*
 * MemMap.h
 *
 * Created: 1/14/2024 5:01:44 PM
 *  Author: Salah Soliman
 */ 


#ifndef MEMMAP_H_
#define MEMMAP_H_


#define PORTA	(*(volatile unsigned char *)0x3B)
#define DDRA	(*(volatile unsigned char *)0x3A)
#define PINA	(*(volatile unsigned char *)0x39)


#define PORTC	(*(volatile unsigned char *)0x35)
#define DDRC	(*(volatile unsigned char *)0x34)
#define PINC	(*(volatile unsigned char *)0x33)



#endif /* MEMMAP_H_ */