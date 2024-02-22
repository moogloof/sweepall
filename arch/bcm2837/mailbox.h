#ifndef MAILBOX_H
#define MAILBOX_H

#include <mmio.h>

#define MAIL0_BASE 0x7e00b880

u32 read_mailbox(u32);
void write_mailbox(u32);

#endif
