LD=arm-none-eabi-ld
CC=arm-none-eabi-gcc
CFLAGS=-Wall -O0 -ffreestanding -nostdinc -nostdlib -nostartfiles -mcpu=cortex-a53

OBJ_DIR=../objs
BUILD_DIR=../build

SRCS=$(shell find . -name "*.s" -or -name "*.c")
OBJS=$(SRCS:%=$(OBJ_DIR)/%.o)

all: $(BUILD_DIR)/kernel.img

$(BUILD_DIR)/kernel.img: $(OBJS)
	mkdir -p $(dir $@)
	$(LD) -nostdlib $(OBJS) -T link.ld -o $@.elf
	arm-none-eabi-objcopy -O binary $@.elf $@

$(OBJ_DIR)/%.o: %
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c -o $@ $<
