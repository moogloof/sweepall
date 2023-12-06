OBJ_DIR=../objs

SRCS=$(shell find . -name "*.s" -or -name "*.c")
OBJS=$(SRCS:%=$(OBJ_DIR)/%.o)

all: $(OBJS)
	$(MAKE) -C data

$(OBJ_DIR)/%.o: %
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c -o $@ $<
