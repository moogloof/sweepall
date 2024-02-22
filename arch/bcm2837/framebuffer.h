#ifndef FRAMEBUFFER_H
#define FRAMEBUFFER_H

#include <mmio.h>

#define RES_WIDTH 1920
#define RES_HEIGHT 1080

void init_framebuffer();

void draw_rect(u32, u32, u32, u32, u32);

void draw_image(u8*, u32, u32, u32, u32, u32);

void update_frame();

#endif
