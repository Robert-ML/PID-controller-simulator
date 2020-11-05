CC=g++
CVERSION=-std=c++11
CFLAGS=-Wall -Wextra -pthread
TEMP_CFLAGS=-Og
RELEASE_CFLAGS=-O2
OUT_NAME=check_pid
C_OUT_NAME=-o $(OUT_NAME)
SOURCES=main.cpp linker.cpp pid.cpp drone.cpp

build:
	$(CC) $(CVERSION) $(VERSION) $(CFLAGS) $(TEMP_CFLAGS) $(SOURCES) $(C_OUT_NAME)

build_release:
	$(CC) $(CVERSION) $(VERSION) $(CFLAGS) $(RELEASE_CFLAGS) $(SOURCES) $(C_OUT_NAME)

run:
	./$(OUT_NAME)

clean:
	rm $(OUT_NAME) altitude.out