OBJ_DIR=../../objs

BINARIES=$(shell find . -name "*.bmp")
OBJS=$(BINARIES:%=$(OBJ_DIR)/%.o)

all: $(OBJS)

$(OBJ_DIR)/%.o: %
	mkdir -p $(dir $@)
	$(OBJCOPY) $(OBJCOPY_FLAGS) -I binary $< $@
