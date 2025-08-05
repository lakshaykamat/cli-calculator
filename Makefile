# Makefile for CLI Calculator

# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -I./include
DEBUG_CFLAGS = -g -O0 -DDEBUG
RELEASE_CFLAGS = -O2

# Directories
SRCDIR = src
BINDIR = bin
INCDIR = include

# Source files
SOURCES = $(wildcard $(SRCDIR)/*.c)
OBJECTS = $(SOURCES:$(SRCDIR)/%.c=$(BINDIR)/%.o)

# Target executable
TARGET = $(BINDIR)/calculator

# Default target
all: $(TARGET)

# Debug build
debug: CFLAGS += $(DEBUG_CFLAGS)
debug: $(TARGET)

# Release build
release: CFLAGS += $(RELEASE_CFLAGS)
release: $(TARGET)

# Build the executable
$(TARGET): $(OBJECTS)
	@echo "Linking $@..."
	@$(CC) $(OBJECTS) -o $(TARGET)
	@echo "Build complete! Run with: ./$(TARGET)"

# Compile source files
$(BINDIR)/%.o: $(SRCDIR)/%.c
	@echo "Compiling $<..."
	@$(CC) $(CFLAGS) -c $< -o $@

# Create necessary directories
$(BINDIR):
	@mkdir -p $(BINDIR)

# Clean build files
clean:
	@echo "Cleaning build files..."
	@rm -rf $(BINDIR)/*.o $(TARGET)
	@echo "Clean complete!"

# Install (copy to system path)
install: $(TARGET)
	@echo "Installing calculator..."
	@sudo cp $(TARGET) /usr/local/bin/
	@echo "Installation complete! You can now run 'calculator' from anywhere."

# Uninstall
uninstall:
	@echo "Uninstalling calculator..."
	@sudo rm -f /usr/local/bin/calculator
	@echo "Uninstallation complete!"

# Run the calculator
run: $(TARGET)
	@echo "Running calculator..."
	@./$(TARGET)

# Test the calculator
test: $(TARGET)
	@echo "Testing calculator..."
	@echo "Testing basic operations..."
	@echo -e "5 + 3\nn" | ./$(TARGET)
	@echo "Testing power operation..."
	@echo -e "2 ^ 3\nn" | ./$(TARGET)
	@echo "Testing error handling..."
	@echo -e "5 / 0\nn" | ./$(TARGET)

# Show help
help:
	@echo "Available targets:"
	@echo "  all      - Build the calculator (default)"
	@echo "  debug    - Build with debug information"
	@echo "  release  - Build optimized release version"
	@echo "  clean    - Remove build files"
	@echo "  install  - Install to system path"
	@echo "  uninstall- Remove from system path"
	@echo "  run      - Build and run the calculator"
	@echo "  test     - Run automated tests"
	@echo "  help     - Show this help message"

# Phony targets
.PHONY: all debug release clean install uninstall run test help 