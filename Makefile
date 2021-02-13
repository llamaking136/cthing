CC = clang
CC_FLAGS = -Ilib -o
OUTPUT = cthing.exe
SOURCE = $(shell find . -name '*.c')

.PHONY: all

all: $(SOURCE)
	$(CC) $(CC_FLAGS) $(OUTPUT) $(SOURCE)

clean: $(OUTPUT)
	rm $(OUTPUT)
