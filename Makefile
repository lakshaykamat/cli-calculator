# =============================================================================
# Simple Makefile for CLI Calculator
# =============================================================================

# =============================================================================
# COMPILER SETTINGS
# =============================================================================
CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -I./include

# =============================================================================
# DIRECTORIES
# =============================================================================
SRCDIR = src
BINDIR = bin
TARGET = $(BINDIR)/calculator

# =============================================================================
# SOURCE FILES
# =============================================================================
SOURCES = $(wildcard $(SRCDIR)/*.c)
OBJECTS = $(SOURCES:$(SRCDIR)/%.c=$(BINDIR)/%.o)

# =============================================================================
# COLOR CODES
# =============================================================================
RED = \033[31m
GREEN = \033[32m
YELLOW = \033[33m
BLUE = \033[34m
MAGENTA = \033[35m
CYAN = \033[36m
WHITE = \033[37m
BOLD = \033[1m
RESET = \033[0m

# =============================================================================
# TARGETS
# =============================================================================

# Default target
all: $(TARGET)

# =============================================================================
# BUILD RULES
# =============================================================================

# Build the calculator
$(TARGET): $(OBJECTS)
	@echo "$(BOLD)$(CYAN)╔══════════════════════════════════════════════════════════════╗$(RESET)"
	@echo "$(BOLD)$(CYAN)║                    LINKING STAGE                            ║$(RESET)"
	@echo "$(BOLD)$(CYAN)╚══════════════════════════════════════════════════════════════╝$(RESET)"
	@echo ""
	@echo "$(YELLOW)🔗 Linking object files into executable...$(RESET)"
	@echo "$(BLUE)Command:$(RESET) $(CC) $(OBJECTS) -o $(TARGET) -lm"
	@echo ""
	$(CC) $(OBJECTS) -o $(TARGET) -lm
	@echo ""
	@echo "$(BOLD)$(GREEN)╔══════════════════════════════════════════════════════════════╗$(RESET)"
	@echo "$(BOLD)$(GREEN)║                   BUILD COMPLETE!                           ║$(RESET)"
	@echo "$(BOLD)$(GREEN)╚══════════════════════════════════════════════════════════════╝$(RESET)"
	@echo ""
	@echo "$(GREEN)✅ Calculator built successfully!$(RESET)"
	@echo "$(GREEN)🚀 You can run it with: $(BOLD)./$(TARGET)$(RESET)"
	@echo ""

# Compile each .c file to .o file
$(BINDIR)/%.o: $(SRCDIR)/%.c
	@echo "$(BOLD)$(MAGENTA)╔══════════════════════════════════════════════════════════════╗$(RESET)"
	@echo "$(BOLD)$(MAGENTA)║                   COMPILING STAGE                          ║$(RESET)"
	@echo "$(BOLD)$(MAGENTA)╚══════════════════════════════════════════════════════════════╝$(RESET)"
	@echo ""
	@echo "$(YELLOW)📝 Compiling source file:$(RESET) $(WHITE)$<$(RESET)"
	@echo "$(YELLOW)📦 Creating object file:$(RESET) $(WHITE)$@$(RESET)"
	@echo "$(BLUE)Command:$(RESET) $(CC) $(CFLAGS) -c $< -o $@"
	@echo ""
	mkdir -p $(BINDIR)
	$(CC) $(CFLAGS) -c $< -o $@
	@echo ""
	@echo "$(GREEN)✅ Compilation successful!$(RESET)"
	@echo ""

# =============================================================================
# UTILITY TARGETS
# =============================================================================

# Clean build files
clean:
	@echo "$(BOLD)$(RED)╔══════════════════════════════════════════════════════════════╗$(RESET)"
	@echo "$(BOLD)$(RED)║                   CLEANING STAGE                             ║$(RESET)"
	@echo "$(BOLD)$(RED)╚══════════════════════════════════════════════════════════════╝$(RESET)"
	@echo ""
	@echo "$(YELLOW)🧹 Removing build directory:$(RESET) $(WHITE)$(BINDIR)$(RESET)"
	rm -rf $(BINDIR)
	@echo ""
	@echo "$(GREEN)✅ Clean complete!$(RESET)"
	@echo ""

# Run the calculator
run: $(TARGET)
	@echo "$(BOLD)$(GREEN)╔══════════════════════════════════════════════════════════════╗$(RESET)"
	@echo "$(BOLD)$(GREEN)║                 RUNNING CALCULATOR                          ║$(RESET)"
	@echo "$(BOLD)$(GREEN)╚══════════════════════════════════════════════════════════════╝$(RESET)"
	@echo ""
	@echo "$(YELLOW)🚀 Starting calculator...$(RESET)"
	@echo ""
	./$(TARGET)

# Install to system (optional)
install: $(TARGET)
	@echo "$(BOLD)$(BLUE)╔══════════════════════════════════════════════════════════════╗$(RESET)"
	@echo "$(BOLD)$(BLUE)║                   INSTALLING                                ║$(RESET)"
	@echo "$(BOLD)$(BLUE)╚══════════════════════════════════════════════════════════════╝$(RESET)"
	@echo ""
	@echo "$(YELLOW)📦 Installing calculator to system...$(RESET)"
	@echo "$(BLUE)Command:$(RESET) sudo cp $(TARGET) /usr/local/bin/"
	@echo ""
	sudo cp $(TARGET) /usr/local/bin/
	@echo ""
	@echo "$(GREEN)✅ Install complete!$(RESET)"
	@echo ""

# Show help
help:
	@echo "$(BOLD)$(CYAN)╔══════════════════════════════════════════════════════════════╗$(RESET)"
	@echo "$(BOLD)$(CYAN)║                CLI CALCULATOR MAKEFILE                      ║$(RESET)"
	@echo "$(BOLD)$(CYAN)╚══════════════════════════════════════════════════════════════╝$(RESET)"
	@echo ""
	@echo "$(BOLD)$(YELLOW)📋 AVAILABLE COMMANDS:$(RESET)"
	@echo ""
	@echo "$(GREEN)  make$(RESET)        - Build the calculator"
	@echo "$(GREEN)  make clean$(RESET)  - Remove build files"
	@echo "$(GREEN)  make run$(RESET)    - Build and run"
	@echo "$(GREEN)  make install$(RESET)- Install to system"
	@echo "$(GREEN)  make help$(RESET)   - Show this help"
	@echo ""
	@echo "$(BOLD)$(MAGENTA)🔧 BUILD PROCESS:$(RESET)"
	@echo ""
	@echo "$(WHITE)1.$(RESET) Compiles all .c files in $(CYAN)src/$(RESET) to .o files in $(CYAN)bin/$(RESET)"
	@echo "$(WHITE)2.$(RESET) Links all .o files into the final executable"
	@echo "$(WHITE)3.$(RESET) Uses math library (-lm) for pow() function"
	@echo ""
	@echo "$(BOLD)$(BLUE)📁 PROJECT STRUCTURE:$(RESET)"
	@echo ""
	@echo "$(CYAN)src/$(RESET)     - Source files (.c)"
	@echo "$(CYAN)include/$(RESET) - Header files (.h)"
	@echo "$(CYAN)bin/$(RESET)     - Build output (gitignored)"
	@echo ""

# =============================================================================
# PHONY TARGETS
# =============================================================================
.PHONY: all clean run install help 