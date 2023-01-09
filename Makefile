# Compilation of Examples and Tests

# Determine whether Mac or Linux
UNAME := $(shell uname)

# Determine ARM or x86
ARCH := $(shell uname -m)

# Set the path to the serial library (e.g. usage: -L$(SERIAL_PATH) -lserial)
ifeq ($(UNAME), Darwin)
	# Mac
	SERIAL_PATH = /usr/local/lib
else
	# Linux
	SERIAL_PATH = /usr/lib

endif	

# Set the Compiler based on OS and Architecture
ifeq ($(UNAME), Darwin)
	# Mac
	CC = g++
else
	ifeq ($(ARCH), x86_64)
		# Linux x86_64
		CC = g++
	else
		# Linux ARM
		CC = arm-linux-gnueabihf-g++
	endif
endif

# Include dir
INCLUDE_DIR = include

# Src dir
SRC_DIR = src

# Object dir
OBJ_DIR = obj

# Exe Dir
EXE_DIR = exe

# Test Dir
TEST_DIR = test

# Specify the C++ standard to use
CXXFLAGS = -std=c++17 -I$(INCLUDE_DIR)

# Echo the compiler
$(info Using $(CC))

.PHONY: all

all: modem.o

tests: test_modem

modem.o: $(SRC_DIR)/modem.cpp $(INCLUDE_DIR)/modem.h
	$(CC) $(CXXFLAGS) -c -o $(OBJ_DIR)/modem.o $(SRC_DIR)/modem.cpp 

test_modem: modem.o $(TEST_DIR)/test_modem.cpp
	$(CC) $(CXXFLAGS) -o $(EXE_DIR)/test_modem.ex $(TEST_DIR)/test_modem.cpp $(OBJ_DIR)/modem.o 
	@echo "./$(EXE_DIR)/test_modem.ex"

clean: 
	rm -f *.o *.ex
	rm -f $(OBJ_DIR)/*.o
	rm -f $(EXE_DIR)/*.ex