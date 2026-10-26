CC = gcc
CFLAGS = -std=c11 -Wall -Wextra -Wpedantic
CPPFLAGS = -Iinclude
TARGET_DIR = target
TARGET = $(TARGET_DIR)/playground.exe
SOURCES = main.c src/array.c src/stack.c src/queue.c src/list.c

.PHONY: all run clean

all: $(TARGET)

$(TARGET): $(SOURCES) $(wildcard include/*.h)
ifeq ($(OS),Windows_NT)
	if not exist $(TARGET_DIR) mkdir $(TARGET_DIR)
else
	mkdir -p $(TARGET_DIR)
endif
	$(CC) $(CPPFLAGS) $(CFLAGS) $(SOURCES) -o $(TARGET)

run: $(TARGET)
ifeq ($(OS),Windows_NT)
	.\$(TARGET)
else
	./$(TARGET)
endif

clean:
ifeq ($(OS),Windows_NT)
	if exist target rmdir /s /q target
	if exist data rmdir /s /q data
else
	rm -rf target data
endif


