#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

vector<int> mem(100);
int pc = 0, temp = 0;
int regA = 0, regB = 0;

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cout << "Use: " << argv[0] << " file.irn" << endl;
        return 1;
    }

    string rutaArchivo = argv[1];
    ifstream archivo(rutaArchivo);
    if (!archivo.is_open()) {
        cout << "Error: The file could not Open:  " << rutaArchivo << endl;
        return 1;
    }

    vector<int> program;
    int instruccion;
    while (archivo >> instruccion) {
        program.push_back(instruccion);
    }
    archivo.close();

    while (pc < program.size()) {
        int instruc = program[pc];

        if (instruc == 1) { temp = program[pc + 1]; pc += 2; }
        else if (instruc == 2) { temp += program[pc + 1]; pc += 2; }
        else if (instruc == 3) { int dir = program[pc + 1]; mem[dir] = temp; pc += 2; }
        else if (instruc == 4) { temp -= program[pc + 1]; pc += 2; }
        else if (instruc == 5) { temp *= program[pc + 1]; pc += 2; }
        else if (instruc == 6) {
            int divisor = program[pc + 1];
            if (divisor != 0) temp /= divisor;
            else { cout << "Division by Zero\n"; break; }
            pc += 2;
        }
        else if (instruc == 7) { temp = mem[program[pc + 1]]; pc += 2; }

        // 💾 NUEVAS instrucciones con registros
        else if (instruc == 10) { regA = program[pc + 1]; pc += 2; }
        else if (instruc == 11) { regB = program[pc + 1]; pc += 2; }
        else if (instruc == 12) { regA += regB; pc += 1; }
        else if (instruc == 13) { int dir = program[pc + 1]; mem[dir] = regA; pc += 2; }

        else if (instruc == 99) { break; }

        else {
            cout << "Invalid: " << instruc << " in Pos=" << pc << endl;
            break;
        }
    }

    cout << "📦 Memory Written:\n";
    for (int i = 0; i < mem.size(); ++i) {
        if (mem[i] != 0) {
            cout << "mem[" << i << "] = " << mem[i] << endl;
        }
    }

    return 0;
}

