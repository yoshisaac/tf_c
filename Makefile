CC=gcc

MAKEFLAGS := --jobs=$(shell nproc)

CFLAGS= -shared -fpic -g

LDFLAGS= -l:libGLEW.so.2.1 -lSDL2 -g

OBJ_FILES=$(shell find . -name '*.c' | sed -e "s/$$/.o/")
OBJS=$(addprefix obj/, $(OBJ_FILES))
BIN=tf_c.so

.PHONY: all clean

#-------------------------------------------------------------------------------

all: $(BIN)

clean:
	rm -f $(OBJS)
	rm -f $(BIN)

#-------------------------------------------------------------------------------

$(BIN): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

obj/%.c.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c -o $@ $<
