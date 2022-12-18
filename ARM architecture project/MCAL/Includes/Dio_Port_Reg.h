#ifndef PORT_REGS_DIO_H
#define PORT_REGS_DIO_H

// Define the port base address offset as a variable address.
#define PORT_BASE_OFFSET(num)             ( num < 4 ? (0x40004000 + 0x1000 * num) : ( 0x40024000 + 0x1000 * (num - 4) ) )
// Define the port address as a variable address.
#define GPIO_DATA_REG_OFFSET(num)                    ( *(volatile uint32*)(PORT_BASE_OFFSET(num)+ 0x3FC) )

#endif