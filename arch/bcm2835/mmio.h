#ifndef MMIO_H
#define MMIO_H

// Board-specific
// See BCM2835 ARM Peripherals 1.2.3
// All port addresses will be written as peripheral (translated by the mmio_read/write functions)
#define PERIPHERAL_BASE 0x7e000000
#define PHYSICAL_BASE 0x3f000000

// Type stuff
// NOTE: May change depending on build system
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;

// MMIO
u32 mmio_read(u32);
void mmio_write(u32, u32);

#endif
