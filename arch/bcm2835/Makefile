LD=arm-none-eabi-ld
export CC=arm-none-eabi-gcc
export CFLAGS=-Wall -Werror -Wpedantic -O0 -ffreestanding -nostdinc -nostdlib -nostartfiles -mcpu=arm1176jzf-s -ggdb -I./
export OBJCOPY=arm-none-eabi-objcopy
export OBJCOPY_FLAGS=-O elf32-littlearm

OBJ_DIR=../../objs
BUILD_DIR=../../build

SRCS=$(shell find . -name "*.s" -or -name "*.c")
TARGET_OBJS=$(SRCS:%=$(OBJ_DIR)/%.o)

all: $(BUILD_DIR)/kernel.img

$(BUILD_DIR)/kernel.img: $(TARGET_OBJS) sweeper
	mkdir -p $(dir $@)
	$(LD) -nostdlib $(shell find $(OBJ_DIR) -name "*.o") -T link.ld -o $@.elf
	$(OBJCOPY) --strip-debug -O binary $@.elf $@

.PHONY: sweeper
sweeper:
	$(MAKE) -C ../../sweeper

$(OBJ_DIR)/%.o: %
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c -o $@ $<
