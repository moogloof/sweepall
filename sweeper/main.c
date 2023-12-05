typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;

extern void init_framebuffer();
extern void draw_rect(u32, u32, u32, u32, u32);

void main() {
	init_framebuffer();
	draw_rect(400, 400, 200, 200, 0xff00ff);

	// Halt
	while (1) {}
}
