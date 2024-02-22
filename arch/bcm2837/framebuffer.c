#include <framebuffer.h>
#include <mailbox.h>

// Mailbox buffer
// Arbitrarily long length
volatile u32 mailbox_buffer[256] __attribute__((aligned(16)));

// Framebuffer info
struct {
	u32 buffer_pointer;
	u32 pitch;
} framebuffer;

// Separate framebuffer to copy over
u8* copy_buffer = (u8*)0x30000000;

void init_framebuffer() {
	// Set size of preset buffer
	mailbox_buffer[0] = 96;
	// Set request code
	mailbox_buffer[1] = 0;

	// First tag to set width and height of screen
	mailbox_buffer[2] = 0x48003;
	mailbox_buffer[3] = 8;
	mailbox_buffer[4] = 0;
	mailbox_buffer[5] = RES_WIDTH;
	mailbox_buffer[6] = RES_HEIGHT;

	// Second tag to set virtual width and height of screen
	mailbox_buffer[7] = 0x48004;
	mailbox_buffer[8] = 8;
	mailbox_buffer[9] = 0;
	mailbox_buffer[10] = RES_WIDTH;
	mailbox_buffer[11] = RES_HEIGHT;

	// Third tag to set depth of pixel
	mailbox_buffer[12] = 0x48005;
	mailbox_buffer[13] = 4;
	mailbox_buffer[14] = 0;
	mailbox_buffer[15] = 24;

	// Fourth tag to set pixel order
	mailbox_buffer[16] = 0x48006;
	mailbox_buffer[17] = 4;
	mailbox_buffer[18] = 0;
	mailbox_buffer[19] = 0;

	// End tag
	mailbox_buffer[20] = 0;
	// Padded tags
	mailbox_buffer[21] = 0;
	mailbox_buffer[22] = 0;
	mailbox_buffer[23] = 0;

	// Send mailbox buffer through mailbox_buffer
	write_mailbox((u32)mailbox_buffer | 8);
	read_mailbox(8);

	// Set size of fetch buffer
	mailbox_buffer[0] = 48;
	// Set request code
	mailbox_buffer[1] = 0;

	// First tag to get pitch of screen
	mailbox_buffer[2] = 0x40008;
	mailbox_buffer[3] = 4;
	mailbox_buffer[4] = 0;
	mailbox_buffer[5] = 0;

	// Second tag to get framebuffer of screen
	mailbox_buffer[6] = 0x40001;
	mailbox_buffer[7] = 8;
	mailbox_buffer[8] = 0;
	mailbox_buffer[9] = 16;
	mailbox_buffer[10] = 0;

	// End tag
	mailbox_buffer[11] = 0;

	// Send mailbox buffer through mailbox
	write_mailbox((u32)mailbox_buffer | 8);
	read_mailbox(8);

	framebuffer.pitch = mailbox_buffer[5];
	framebuffer.buffer_pointer = mailbox_buffer[9];
}

void draw_rect(u32 x, u32 y, u32 width, u32 height, u32 rgb) {
	// Just exit if x and y outside
	if (x >= RES_WIDTH || y >= RES_HEIGHT) return;

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

void draw_image(u8* image, u32 x, u32 y, u32 width, u32 height, u32 pitch) {
	// Just exit if x and y outside
	if (x >= RES_WIDTH || y >= RES_HEIGHT) return;

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
			copy_buffer[buffer_index + 3*j] = image[3*j + pitch*i];
			copy_buffer[buffer_index + 3*j + 1] = image[3*j + pitch*i + 1];
			copy_buffer[buffer_index + 3*j + 2] = image[3*j + pitch*i + 2];
		}
		buffer_index += framebuffer.pitch;
	}
}

void update_framebuffer() {
	u32* buffer_pointer = (u32*)(framebuffer.buffer_pointer);
	for (int i = 0; i < RES_HEIGHT*framebuffer.pitch / sizeof(u32); i++)
		buffer_pointer[i] = ((u32*)copy_buffer)[i];
}
