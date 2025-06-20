# 🧠 BBVM – BlueBox Virtual Memory

**BBVM** is a simple virtual machine written in C++ that simulates memory, registers, and a minimal instruction set. It reads and executes `.irn` (Instruction Real Numbered) files, acting as a low-level emulator.

> Developed by Gabriel G. M. @ggmaldo

---

## 🚀 Features

- Virtual CPU with `temp`, RAM memory, and registers `A` and `B`
- Arithmetic operations: `LOAD`, `ADD`, `SUB`, `MUL`, `DIV`
- Memory read and write
- Extended instructions: `LOADA`, `LOADB`, `ADDAB`, `STOREA`
- Program loading from `.irn` files
- Clean CMake support for easy building

---

## 📁 Project Structure

```bash
bbvm/
├── src/
│   └── main.cpp         # Virtual Machine source code
├── programs/
│   └── program.irn      # Example IRN program
├── build/               # Build folder (generated)
├── CMakeLists.txt       # Build configuration
└── README.md            # This file
```
# How to Build?
### clone the Repo
```
git clone https://github.com/ggmaldo/bbvm
```
### Create build directory and compile
```
mkdir build && cd build && cmake .. && make
```
### Run the IRN Program
```
./build/BBVM programs/program.irn

```
## 📝 IRN File Format
.irn files contain numeric instructions and parameters, like:
```
1 10     # LOAD 10
2 5      # ADD 5
3 0      # STORE temp → mem[0]
99       # HALT
```
## OutPut
The virtual machine will print all memory positions that were written to (non-zero):
```
mem[0] = 25
```
## 🤝 Contributing

Feel free to open pull requests with new features, bug fixes, or example .irn programs. You’re welcome to help improve the instruction set or architecture.
## 📜 License

This project is licensed under the MIT License.

# More Information
here is an image about how the VM works:

