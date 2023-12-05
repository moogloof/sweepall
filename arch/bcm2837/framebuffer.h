#ifndef FRAMEBUFFER_H
#define FRAMEBUFFER_H

#include <mmio.h>

#define MAIL0_BASE 0x7e00b880

void init_framebuffer();

void draw_rect(u32, u32, u32, u32, u32);

#endif
