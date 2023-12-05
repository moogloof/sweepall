#include <mmio.h>

u32 mmio_read(u32 address) {
	return *((u32*)(address - PERIPHERAL_BASE + PHYSICAL_BASE));
}

void mmio_write(u32 address, u32 value) {
	*((u32*)(address - PERIPHERAL_BASE + PHYSICAL_BASE)) = value;
}
