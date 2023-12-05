typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;

extern void init_framebuffer();
extern void draw_rect(u32, u32, u32, u32, u32);

void main() {
	u32 x = 0;
	u32 y = 0;
	u32 xvel = 1;
	u32 yvel = 1;
	u32 w = 100;
	u32 h = 100;
	u32 color = 0x0000ff;

	init_framebuffer();

	// Bouncing thingy
	while (1) {
		draw_rect(0, 0, 1920, 1080, 0);
		x += xvel;
		y += yvel;

		if (x + w >= 1920) {
			xvel = -1;
		} else if (x <= 0) {
			xvel = 1;
		}

		if (y + h >= 1080) {
			yvel = -1;
		} else if (y <= 0) {
			yvel = 1;
		}

		draw_rect(x, y, w, h, color);
	}
}
