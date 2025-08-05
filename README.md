# CLI Calculator

A simple yet powerful command-line calculator written in C that supports basic arithmetic operations and advanced mathematical functions with a beautiful, colorful build system.

## 🚀 Features

### Basic Operations
- **Addition** (`+`): Add two numbers
- **Subtraction** (`-`): Subtract second number from first
- **Multiplication** (`*`): Multiply two numbers
- **Division** (`/`): Divide first number by second
- **Power** (`^`): Raise first number to the power of second

### Advanced Features
- **Math Library Integration**: Uses standard `pow()` function for accurate power calculations
- **Error Handling**: Robust input validation and error messages
- **Interactive Interface**: User-friendly command-line interface
- **Input Validation**: Handles invalid inputs gracefully
- **Organized Project Structure**: Clean separation of source, headers, and binaries
- **Colorful Build System**: Beautiful, verbose Makefile with colors and emojis
- **System Integration**: Install as `calc` command for global access

## 📋 Requirements

- **Compiler**: GCC or any C99 compatible compiler
- **Operating System**: Linux, macOS, or Windows (with appropriate compiler)
- **Dependencies**: Math library (linked with `-lm`)
- **Build Tool**: Make (optional, for easy building)

## 🛠️ Installation

### Prerequisites
Make sure you have a C compiler and Make installed on your system:

**Ubuntu/Debian:**
```bash
sudo apt update
sudo apt install build-essential make
```

**macOS:**
```bash
xcode-select --install
# Make is included with Xcode Command Line Tools
```

**Windows:**
Install MinGW or use WSL (Windows Subsystem for Linux)

### Building the Calculator

#### Using Make (Recommended)
1. **Clone or download the project files**
2. **Navigate to the project directory**
   ```bash
   cd cli-calculator
   ```

3. **Build the program**
   ```bash
   make
   ```

4. **Run the calculator**
   ```bash
   ./bin/calculator
   ```

#### Manual Compilation
If you prefer to compile manually:
```bash
mkdir -p bin
gcc -Wall -Wextra -std=c99 -I./include -c src/calculator.c -o bin/calculator.o
gcc -Wall -Wextra -std=c99 -I./include -c src/main.c -o bin/main.o
gcc bin/calculator.o bin/main.o -o bin/calculator -lm
```

## 📖 Usage

### Starting the Calculator

#### From Project Directory
```bash
./bin/calculator
```

#### After System Installation
```bash
calc
```

### Input Format
The calculator accepts expressions in the format:
```
number1 operator number2
```

**Examples:**
```
5 + 3
10 - 4
6 * 7
15 / 3
2 ^ 3
```

### Supported Operations

| Operation | Symbol | Example | Result |
|-----------|--------|---------|--------|
| Addition | `+` | `5 + 3` | `8.00` |
| Subtraction | `-` | `10 - 4` | `6.00` |
| Multiplication | `*` | `6 * 7` | `42.00` |
| Division | `/` | `15 / 3` | `5.00` |
| Power | `^` | `2 ^ 3` | `8.00` |

### Interactive Session Example
```
=== Simple CLI Calculator ===
Enter an expression (e.g., 5 + 2): 10 + 5
15.00
Do you want to perform another calculation? (y/n): y
Enter an expression (e.g., 5 + 2): 2 ^ 8
256.00
Do you want to perform another calculation? (y/n): n
Thank you for using the calculator!
```

## 🔧 Technical Details

### Power Implementation
The calculator uses the standard C math library `pow()` function for:
- **Integer exponents** (positive and negative)
- **Fractional exponents** (square roots, cube roots, etc.)
- **Special cases** (0^0, 1^x, etc.)
- **Accurate calculations** with proper error handling

### Error Handling
The calculator includes comprehensive error handling for:
- **Division by zero**
- **Invalid input format**
- **Unsupported operators**
- **Input buffer overflow**

### Project Structure
```
cli-calculator/
├── src/              # Source files
│   ├── main.c        # Main program logic and user interface
│   └── calculator.c  # Mathematical operations implementation
├── include/          # Header files
│   └── calculator.h  # Function declarations and constants
├── bin/              # Build output (gitignored)
│   ├── calculator    # Compiled executable
│   ├── main.o        # Object files
│   └── calculator.o  # Object files
├── Makefile          # Beautiful build configuration
├── .gitignore        # Git ignore rules
└── README.md         # This file
```

## 🛠️ Build System

### Beautiful Colorful Makefile
The project features a stunning, verbose Makefile with:
- **🎨 Color-coded output** for different stages
- **📦 Visual boxes** around each build stage
- **😊 Emojis** for better visual appeal
- **📝 Detailed explanations** of what's happening
- **🔍 Verbose commands** showing exact gcc calls

### Available Make Targets

| Target | Description |
|--------|-------------|
| `make` or `make all` | Build the calculator (default) |
| `make clean` | Remove build files |
| `make run` | Build and run the calculator |
| `make install` | Install as `calc` command |
| `make uninstall` | Remove `calc` command |
| `make help` | Show beautiful help message |

### Build Process Example
```
╔══════════════════════════════════════════════════════════════╗
║                   COMPILING STAGE                          ║
╚══════════════════════════════════════════════════════════════╝

📝 Compiling source file: src/calculator.c
📦 Creating object file: bin/calculator.o
Command: gcc -Wall -Wextra -std=c99 -I./include -c src/calculator.c -o bin/calculator.o

✅ Compilation successful!

╔══════════════════════════════════════════════════════════════╗
║                    LINKING STAGE                            ║
╚══════════════════════════════════════════════════════════════╝

🔗 Linking object files into executable...
Command: gcc bin/calculator.o bin/main.o -o bin/calculator -lm

╔══════════════════════════════════════════════════════════════╗
║                   BUILD COMPLETE!                           ║
╚══════════════════════════════════════════════════════════════╝

✅ Calculator built successfully!
🚀 You can run it with: ./bin/calculator
```

### Examples
```bash
# Build the calculator
make

# Clean build files
make clean

# Build and run
make run

# Install as 'calc' command (requires sudo)
make install

# Remove 'calc' command (requires sudo)
make uninstall

# Show beautiful help
make help
```

## 🚀 System Installation

### Install as Global Command
```bash
# Build and install
make install
```

After installation, you can use `calc` from anywhere:
```bash
# Run interactively
calc

# Use with pipes
echo "5 + 3" | calc
echo "2 ^ 8" | calc

# Test operations
echo -e "10 - 4\nn" | calc
echo -e "6 * 7\nn" | calc
echo -e "15 / 3\nn" | calc
```

### Uninstall
```bash
make uninstall
```

## 🧪 Testing

### Manual Testing
```bash
# Basic operations
echo -e "5 + 3\nn" | ./bin/calculator
echo -e "10 - 4\nn" | ./bin/calculator
echo -e "6 * 7\nn" | ./bin/calculator
echo -e "15 / 3\nn" | ./bin/calculator

# Power operations
echo -e "2 ^ 3\nn" | ./bin/calculator
echo -e "4 ^ 0.5\nn" | ./bin/calculator
echo -e "2 ^ -2\nn" | ./bin/calculator

# Error handling
echo -e "5 / 0\nn" | ./bin/calculator
echo -e "invalid\nn" | ./bin/calculator
```

### Testing After Installation
```bash
# Test the 'calc' command
echo -e "5 + 3\nn" | calc
echo -e "2 ^ 3\nn" | calc
echo -e "5 / 0\nn" | calc
```

## 🐛 Troubleshooting

### Common Issues

**1. Compilation Error: "command not found: gcc"**
- **Solution**: Install a C compiler (see Installation section)

**2. Make Error: "command not found: make"**
- **Solution**: Install Make (see Installation section)

**3. Permission Denied Error**
- **Solution**: Make the executable file executable:
  ```bash
  chmod +x bin/calculator
  ```

**4. Input Not Working Properly**
- **Solution**: Ensure you're using the correct input format with spaces between numbers and operators

**5. Build Fails with Include Errors**
- **Solution**: Ensure you're running make from the project root directory

**6. Math Library Linking Error**
- **Solution**: The Makefile automatically includes `-lm` flag for math library linking

**7. "calc: command not found" after installation**
- **Solution**: Try restarting your terminal or run `hash -r` to refresh command cache

## 🔮 Future Enhancements

Potential improvements for future versions:
- [ ] Scientific calculator functions (sin, cos, log, etc.)
- [ ] Memory functions (store/recall)
- [ ] Calculation history
- [ ] File input/output support
- [ ] Unit conversions
- [ ] Expression parser for complex expressions
- [ ] Configuration options
- [ ] GUI version
- [ ] Unit testing framework
- [ ] Continuous integration
- [ ] More advanced mathematical operations
- [ ] Custom themes for the build system

## 📝 License

This project is open source and available under the MIT License.

## 🤝 Contributing

Contributions are welcome! Please feel free to submit a Pull Request.

### Development Setup
1. Fork the repository
2. Create a feature branch
3. Make your changes
4. Test thoroughly
5. Submit a pull request

### Development Guidelines
- Follow the existing code style
- Add tests for new features
- Update documentation as needed
- Use the provided Makefile for building
- Maintain the beautiful build system aesthetics

## 📞 Support

If you encounter any issues or have questions:
1. Check the troubleshooting section above
2. Review the code comments for implementation details
3. Open an issue on the project repository

---

**Happy Calculating! 🧮✨**
