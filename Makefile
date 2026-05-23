LIB_DIRS = $(wildcard src/libs/*/ src/libs/*/*/)
CFLAGS = -Ilibs $(addprefix -I,$(LIB_DIRS))
TARGET = ./output/main
SRC = $(shell find src -name '*.c')

$(TARGET): $(SRC) | output
	gcc $(CFLAGS) $^ -o $@

output:
	mkdir -p output

run: $(TARGET)
	@clear
	@$(TARGET)

clean:
	rm -rf output

.PHONY: run clean