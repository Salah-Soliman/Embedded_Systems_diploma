
/*
 * Utilites.h
 *
 * Created:
 *  Author: Salah Soliman
 */ 
#ifndef UTILITES_H_
#define UTILITES_H_

#define SetBit(Reg,Bit)			(Reg = Reg | (1<<Bit))
#define ClearBit(Reg,Bit)		(Reg = Reg &~ (1<<Bit))
#define ToggleBit(Reg,Bit)		(Reg = Reg ^ (1<<Bit))
#define ReadBit(Reg,Bit)		((Reg>>Bit)&1)




#endif /* UTILITES_H_ */