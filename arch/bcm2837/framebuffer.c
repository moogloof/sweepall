#include <framebuffer.h>

// MMIO ports
// Source: https://elinux.org/RPi_Framebuffer#Memory_mapped_registers
volatile u32 mail0_read = MAIL0_BASE;
volatile u32 mail0_status = MAIL0_BASE + 0x18;
volatile u32 mail0_write = MAIL0_BASE + 0x20;

// Framebuffer struct
// Source: https://elinux.org/RPi_Framebuffer#Format_of_GPU_Framebuffer_Structure
volatile struct {
	u32 width; // Check VideoCore 4 support
	u32 height; // Check VideoCore 4 support
	u32 virtual_width; // Set to width
	u32 virtual_height; // Set to height
	u32 pitch; // Init to 0; set by GPU
	u32 depth; // Use 24
	u32 x_offset; // Init to 0
	u32 y_offset; // Init to 0
	u8* buffer_pointer; // Init to 0; set by GPU
	u32 size; // Init to 0; set by GPU
} framebuffer;

// Separate framebuffer to copy over
u8* copy_buffer = (u8*)0x30000000;

void init_framebuffer() {
	while (1) {
		u32 mail0_read_content = 0;

		// Set dimensions
		framebuffer.width = RES_WIDTH;
		framebuffer.height = RES_HEIGHT;
		framebuffer.virtual_width = framebuffer.width;
		framebuffer.virtual_height = framebuffer.height;

		// Set pixel stuff
		framebuffer.pitch = 0;
		framebuffer.depth = 24;
		framebuffer.x_offset = 0;
		framebuffer.y_offset = 0;

		// Buffer
		framebuffer.buffer_pointer = 0;
		framebuffer.size = 0;

		// Wait till channel open
		while (mmio_read(mail0_status) >> 31);
		mmio_write(mail0_write, ((u32)(&framebuffer) & 0xfffffff0) | 1);

		while ((mail0_read_content & 0xf) != 1) {
			// Wait till channel not empty
			while ((mmio_read(mail0_status) >> 30) & 1);
			mail0_read_content = mmio_read(mail0_read);
		}

		// Check if valid read
		if (!(mail0_read_content >> 4))
			break;
	}
}

void draw_rect(u32 x, u32 y, u32 width, u32 height, u32 rgb) {
	// Calculate start index of buffer
	u32 buffer_index = 3*x + framebuffer.pitch*y;

	// Calculate true width and height
	u32 true_width = width;
	u32 true_height = height;

	if (true_width + x >= RES_WIDTH)
		true_width = RES_WIDTH - x;
	if (true_height + y >= RES_HEIGHT)
		true_height = RES_HEIGHT - y;

	// Loop for setting
	for (int i = 0; i < true_height; i++) {
		for (int j = 0; j < true_width; j++) {
			copy_buffer[buffer_index + 3*j] = rgb & 0xff;
			copy_buffer[buffer_index + 3*j + 1] = (rgb >> 8) & 0xff;
			copy_buffer[buffer_index + 3*j + 2] = (rgb >> 16) & 0xff;
		}
		buffer_index += framebuffer.pitch;
	}
}

void update_framebuffer() {
	for (int i = 0; i < RES_HEIGHT*framebuffer.pitch; i++)
		framebuffer.buffer_pointer[i] = copy_buffer[i];
}
