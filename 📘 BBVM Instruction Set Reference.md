# 📘 BBVM Instruction Set Manual

This document describes all supported `.irn` instructions (numeric opcodes) used by the BBVM (BlueBox Virtual Memory) virtual machine.

---

## 🧠 General Behavior

- BBVM reads a list of numbers from a `.irn` file.
- Each number represents either an **instruction** or a **parameter**.
- The `program counter (pc)` moves through the list based on how many parameters each instruction requires.

---

## 🗃️ Registers and Memory

- `TEMP` → a temporary general-purpose register
- `REGA` / `REGB` → register A and B for more complex operations
- `MEMORY` → 100-slot memory (`mem[0]` to `mem[99]`)

---

## 🧾 List of Instructions

| Code | Name       | Parameters | Description |
|------|------------|------------|-------------|
| `1`  | `LOAD`     | 1 value    | Load a value into `TEMP` |
| `2`  | `ADD`      | 1 value    | Add a value to `TEMP` |
| `3`  | `STORE`    | 1 address  | Store `TEMP` into `mem[address]` |
| `4`  | `SUB`      | 1 value    | Subtract a value from `TEMP` |
| `5`  | `MUL`      | 1 value    | Multiply `TEMP` by a value |
| `6`  | `DIV`      | 1 value    | Divide `TEMP` by a value (safe: prevents division by zero) |
| `7`  | `LOADM`    | 1 address  | Load value from `mem[address]` into `TEMP` |
| `10` | `LOADA`    | 1 value    | Load value into `REGA` |
| `11` | `LOADB`    | 1 value    | Load value into `REGB` |
| `12` | `ADDAB`    | 0          | Add `REGB` to `REGA` (`REGA = REGA + REGB`) |
| `13` | `STOREA`   | 1 address  | Store `REGA` into `mem[address]` |
| `99` | `HALT`     | 0          | Stop execution of the program |

---

## 🧪 Examples

### 🔹 Example 1: Basic arithmetic with TEMP

```irn
1 20     # LOAD 20
2 5      # ADD 5 → TEMP = 25
3 0      # STORE at mem[0]
99
