typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;

extern void init_framebuffer();
extern void draw_rect(u32, u32, u32, u32, u32);
extern void update_framebuffer();

void main() {
	u32 x = 0;
	u32 y = 0;
	u32 xvel = 5;
	u32 yvel = 5;
	u32 w = 231;
	u32 h = 231;
	u32 color = 0xffc300;

	init_framebuffer();

	// Bouncing thingy
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

		draw_rect(x, y, w, h, color);

		update_framebuffer();
	}
}
