/*
 * interrupt_private.h
 *
 *  Created on: 12 Apr 2019
 *      Author: MohamedSaa3D
 */

#ifndef _INTERRUPT_PRIVATE_H_
#define _INTERRUPT_PRIVATE_H_



/*---------------------------------------------------------------------------------------*/
/* ------------------------ Addressing the INTERRUPT registers  -------------------------*/
/*---------------------------------------------------------------------------------------*/

#define SREG   *((volatile u8*)(0x5F))
#define GICR   *((volatile u8*)(0x5B))
#define GIFR   *((volatile u8*)(0x5A))
#define MCUCR  *((volatile u8*)(0x55))
#define MCUCSR *((volatile u8*)(0x54))

/*---------------------------------------------------------------------------------------*/
/* ------------------------ Indexing the configuration options  -------------------------*/
/*---------------------------------------------------------------------------------------*/

//#define  INTERRUPT_DISABLED     0
//#define  INTERRUPT_ENABLED      1
//
//#define  LOW_LEVEL              0
//#define  ANY_LOGIC_CHANGE       1
//#define  FALLING_EDGE           2
//#define  RISING_EDGE            3




#endif /* _INTERRUPT_PRIVATE_H_ */
