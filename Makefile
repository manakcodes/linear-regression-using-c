# Compiler and flags
CC      := gcc
CFLAGS  := -Wall -Wextra -Wpedantic -std=c11 -O2
LDFLAGS := -lm

# Directories
SRC_DIR := src

# Files
MAIN_SRC := Main.c
TEST_SRC := Test.c

# Targets
MAIN_BIN := Main
TEST_BIN := Test

# Headers
HEADERS := linreg.h \
           $(SRC_DIR)/core.h \
           $(SRC_DIR)/io.h \
           $(SRC_DIR)/utility.h

# Default target
all: $(MAIN_BIN)

# Build main program
$(MAIN_BIN): $(MAIN_SRC) $(HEADERS)
	$(CC) $(CFLAGS) $(MAIN_SRC) -o $(MAIN_BIN) $(LDFLAGS)

# Build test binary
test: $(TEST_BIN)

$(TEST_BIN): $(TEST_SRC) $(HEADERS)
	$(CC) $(CFLAGS) $(TEST_SRC) -o $(TEST_BIN) $(LDFLAGS)

# Run tests
run-test: test
	./$(TEST_BIN)

# Clean build artifacts
clean:
	rm -f $(MAIN_BIN) $(TEST_BIN)

.PHONY: all test run-test clean