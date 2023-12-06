#include <image.h>

typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;

// Basic functions we want from each platform
extern void init_framebuffer();
extern void draw_rect(u32, u32, u32, u32, u32);
extern void draw_image(u8*, u32, u32, u32, u32, u32);
extern void update_framebuffer();

extern bmp_header _binary_face_bmp_start;

void main() {
	u32 x = 0;
	u32 y = 0;
	u32 xvel = 5;
	u32 yvel = 5;
	u32 w = 200;
	u32 h = 200;
//	u32 color = 0xffc300;

	// Setup framebuffer
	init_framebuffer();

	// Bouncing face
	while (1) {
		draw_rect(x, y, w, h, 0);
		x += xvel;
		y += yvel;

		if (x + w >= 1920) {
			xvel = -5;
		} else if (x <= 0) {
			xvel = 5;
		}

		if (y + h >= 1080) {
			yvel = -5;
		} else if (y <= 0) {
			yvel = 5;
		}

		draw_image((u8*)(&_binary_face_bmp_start) + _binary_face_bmp_start.offset, x, y, w, h, 4*((3*w + 3) / 4));

		update_framebuffer();
	}
}
