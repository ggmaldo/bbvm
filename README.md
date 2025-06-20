
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
# More Information
here is an image about how the VM works:
![BBVM](https://github.com/user-attachments/assets/4b448d40-94d2-4b6f-b44a-7f663e556032)
## Explanation:
---
---
 ## 🧩 Components of the Diagram
### 🟦 MEMORY
-Labeled box on the left.
-It represents a block of 100 memory slots (like mem[0], mem[1], ..., mem[99]).
-Used to store values that are written by instructions like STORE or STOREA.
-Can be read using the LOADM instruction.

### ➡️ Arrow: Memory → CPU
- This arrow shows the flow of data from memory into the CPU.
- Example: temp = mem[5] or regA = mem[10].
---
 ## 🧠 CPU Block
This is where the processing happens. It includes:
 #### TEMP
- A temporary register for performing operations.
- Used by basic instructions like LOAD, ADD, MUL, etc.
- Think of it like a workspace.
#### REGA and REGB
- General-purpose registers.
- Used for register-to-register arithmetic, like ADDAB (regA += regB).
- Instructions LOADA, LOADB, STOREA interact with them.
#### INSTRUCTION
- The current instruction being executed.
- It's fetched from the .irn program and interpreted.
  - After each instruction, pc += 1 or pc += 2 depending on if it had a parameter.
  ---
## 🧠 Execution Flow Summary

1. Program is loaded from a .irn file into memory as a list of numbers.
2. The CPU reads the next instruction from the program.
3 .Depending on the opcode:
   3.1 It modifies TEMP, REGA, or REGB
4. It writes or reads from MEMORY
5. Continues until 99 (HALT) is reached.
## Real Example
```
1 10      # LOAD 10 → TEMP = 10
2 5       # ADD 5   → TEMP = 15
3 0       # STORE 0 → MEM[0] = 15
99        # HALT
```
In the diagram:
- TEMP becomes 15
- Instruction STORE moves it into mem[0]
- MEMORY now holds the result

For more info on how to create a .irn program go to 📘 BBVM Instruction Set Reference.md

  ## 🤝 Contributing

Feel free to open pull requests with new features, bug fixes, or example .irn programs. You’re welcome to help improve the instruction set or architecture.
## 📜 License

This project is licensed under the MIT License.
