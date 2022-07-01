#include <cstdio>
int input, inst[32], adder, pc, instruction, x;

void exec() {
    adder = 0, pc = 0;
    while (true) {
        instruction = inst[pc];
        x = instruction & 0x1f;
        pc++;
        pc &= 0x1f;
        switch (instruction >> 5) {
            case 0:
                inst[x] = adder;
                break;
            case 1:
                adder = inst[x];
                break;
            case 2:
                if (!adder) pc = x;
                break;
            case 4:
                adder--;
                adder &= 0xff;
                break;
            case 5:
                adder++;
                adder &= 0xff;
                break;
            case 6:
                pc = x;
                break;
            case 7:
                return;
            default:
                break;
        }
    }
}
void binAdder() {
    for (int i=7; 0<=i; i--) {
        if (adder & (1 << i)) printf("1");
        else printf("0");
    }
    printf("\n");
}
int main() {
    while (true) {
        for (int i=0; i<32; i++) {
            inst[i] = 0;
            for (int j=0; j<8; j++) {
                if (scanf("%1d", &input) < 0) return 0;
                inst[i] = 2 * inst[i] + input;
            }
        }
        exec();
        binAdder();
    }
    return 0;
}