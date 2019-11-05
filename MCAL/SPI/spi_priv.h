/*
 * spi_priv.h
 *
 *  Created on: 11 May 2019
 *      Author: MohamedSaa3D
 */

#ifndef _SPI_PRIV_H_
#define _SPI_PRIV_H_


#define SPCR  *( (volatile u8*)(0x2D)  )
#define SPSR  *( (volatile u8*)(0x2E)  )
#define SPDR  *( (volatile u8*)(0x2F)  )


#define MASTER 0
#define SLAVE  1



#endif
