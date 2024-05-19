CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -v

SRC_DIR = ./src
OBJ_DIR = ./obj
BIN_DIR = ./bin

SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS))
EXEC = $(BIN_DIR)/bls
INSTALL_DIR = /usr/local/bin

.PHONY: all clean directories install

all: directories $(EXEC)

$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@
	@echo "Build complete. Run 'make install' to install the executable."

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

directories:
	mkdir -p $(OBJ_DIR) $(BIN_DIR)

install: $(EXEC)
	cp $(EXEC) $(INSTALL_DIR)
	@echo "Executable installed to $(INSTALL_DIR). You can run it as 'bls' from anywhere."

clean:
	rm -rf $(OBJ_DIR)/* $(BIN_DIR)/*
