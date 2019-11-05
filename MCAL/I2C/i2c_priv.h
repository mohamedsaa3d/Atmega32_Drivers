
#ifndef _I2C_PRIV_H_
#define _I2C_PRIV_H_

/* Registers */
#define TWBR  *( (volatile u8*)(0x20) )
#define TWSR  *( (volatile u8*)(0x21) )
#define TWAR  *( (volatile u8*)(0x22) )
#define TWDR  *( (volatile u8*)(0x23) )
#define TWCR  *( (volatile u8*)(0x56) )

/* Bits */
#define TWIE    0
#define TWEN    2
#define TWWC    3
#define TWSTO   4
#define TWSTA   5
#define TWEA    6
#define TWINT   7


#define TWPS0   0
#define TWPS1   1
#define TWS3    3
#define TWS4    4
#define TWS5    5
#define TWS6    6
#define TWS7    7

#define TWGCE   0


#endif
