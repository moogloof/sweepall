#ifndef MMIO_H
#define MMIO_H

// Board-specific
// See BCM2835 ARM Peripherals 1.2.3
#define PERIPHERAL_BASE

// Type stuff
// NOTE: May change depending on build system
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;

// MMIO
u32 mmio_read(u32);
u32 mmio_write(u32, u32);

#endif
