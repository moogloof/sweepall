#ifndef FRAMEBUFFER_H
#define FRAMEBUFFER_H

#include <mmio.h>

#define MAIL0_BASE 0x7e00b880
#define RES_WIDTH 1280
#define RES_HEIGHT 720

void init_framebuffer();

void draw_rect(u32, u32, u32, u32, u32);

void update_frame();

#endif
