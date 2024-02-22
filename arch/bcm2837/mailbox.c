#include <mailbox.h>
#include <mmio.h>

// MMIO ports
// Source: https://elinux.org/RPi_Framebuffer#Memory_mapped_registers
volatile u32 mail0_read = MAIL0_BASE;
volatile u32 mail0_status = MAIL0_BASE + 0x18;
volatile u32 mail0_write = MAIL0_BASE + 0x20;

u32 read_mailbox(u32 channel) {
	// Keep reading until correct channel
	while (1) {
		// Wait until mail_empty is cleared
		while ((mmio_read(mail0_status) >> 30) & 1);

		// Read and check channel
		u32 read_value = mmio_read(mail0_read);
		if((read_value & 0xf) == channel)
			return read_value;
	}
}

void write_mailbox(u32 packet) {
	// Wait until mail full is cleared
	while (mmio_read(mail0_status) >> 31);

	// Write to mailbox
	mmio_write(mail0_write, packet);
}
