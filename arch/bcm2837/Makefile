LD=arm-none-eabi-ld
export CC=arm-none-eabi-gcc
export CFLAGS=-Wall -Werror -Wpedantic -O3 -ffreestanding -nostdinc -nostdlib -nostartfiles -mcpu=cortex-a53 -I./

OBJ_DIR=../../objs
BUILD_DIR=../../build

SRCS=$(shell find . -name "*.s" -or -name "*.c")
TARGET_OBJS=$(SRCS:%=$(OBJ_DIR)/%.o)

all: $(BUILD_DIR)/kernel.img

$(BUILD_DIR)/kernel.img: $(TARGET_OBJS) sweeper
	mkdir -p $(dir $@)
	$(LD) -nostdlib $(shell find $(OBJ_DIR) -name "*.o") -T link.ld -o $@.elf
	arm-none-eabi-objcopy -O binary $@.elf $@

.PHONY: sweeper
sweeper:
	$(MAKE) -C ../../sweeper

$(OBJ_DIR)/%.o: %
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c -o $@ $<
