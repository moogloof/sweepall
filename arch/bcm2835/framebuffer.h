#ifndef FRAMEBUFFER_H
#define FRAMEBUFFER_H

#include <mmio.h>

#define MAIL0_BASE 0x7e00b880
#define RES_WIDTH 640
#define RES_HEIGHT 480

void init_framebuffer();

void draw_rect(u32, u32, u32, u32, u32);

void draw_image(u8*, u32, u32, u32, u32, u32);

void update_frame();

#endif
