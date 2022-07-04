#include <cstdio>
#include <cstring>
#include <vector>
#include <cmath>
#define ERR 2000000000
#define MAX 1000000000
using namespace std;
enum Commands {
    NUM, POP, INV, DUP, SWP, ADD, SUB, MUL, DIV, MOD
};

long long int pop(vector<int>& stack) {
    if (!stack.size()) return ERR;
    long long int ret = stack.back();
    stack.pop_back();
    return ret;
}
void sol(int V, vector<int>& machine) {
    vector<int> stack = { V };
    long long int op1, op2, res;
    bool error = false;

    for (int i=0; i<machine.size(); i++) {
        switch (machine[i]) {
            case (NUM):
                stack.push_back(machine[++i]);
                break;
            case (POP):
                op1 = pop(stack);
                if (op1 == ERR) error = true;
                break;
            case (INV):
                op1 = pop(stack);
                if (op1 == ERR) error = true;
                else stack.push_back(-op1);
                break;
            case (DUP):
                op1 = pop(stack);
                if (op1 == ERR) error = true;
                else {
                    stack.push_back(op1);
                    stack.push_back(op1);
                }
                break;
            case (SWP):
                op1 = pop(stack);
                if (op1 == ERR) {
                    error = true;
                    break;
                }
                op2 = pop(stack);
                if (op2 == ERR) {
                    error = true;
                    break;
                }
                stack.push_back(op1);
                stack.push_back(op2);
                break;
            case (ADD):
                op1 = pop(stack);
                if (op1 == ERR) {
                    error = true;
                    break;
                }
                op2 = pop(stack);
                if (op2 == ERR) {
                    error = true;
                    break;
                }
                res = op1 + op2;
                if (MAX < abs(res)) {
                    error = true;
                    break;
                }
                stack.push_back(res);
                break;
            case (SUB):
                op1 = pop(stack);
                if (op1 == ERR) {
                    error = true;
                    break;
                }
                op2 = pop(stack);
                if (op2 == ERR) {
                    error = true;
                    break;
                }
                res = op2 - op1;
                if (MAX < abs(res)) {
                    error = true;
                    break;
                }
                stack.push_back(res);
                break;
            case (MUL):
                op1 = pop(stack);
                if (op1 == ERR) {
                    error = true;
                    break;
                }
                op2 = pop(stack);
                if (op2 == ERR) {
                    error = true;
                    break;
                }
                res = op1 * op2;
                if (MAX < abs(res)) {
                    error = true;
                    break;
                }
                stack.push_back(op1 * op2);
                break;
            case (DIV):
                op1 = pop(stack);
                if (op1 == ERR || op1 == 0) {
                    error = true;
                    break;
                }
                op2 = pop(stack);
                if (op2 == ERR) {
                    error = true;
                    break;
                }
                res = op1 * op2 < 0? -(abs(op2) / abs(op1)) : abs(op2) / abs(op1);
                if (MAX < abs(res)) {
                    error = true;
                    break;
                }
                stack.push_back(res);
                break;
            case (MOD):
                op1 = pop(stack);
                if (op1 == ERR || op1 == 0) {
                    error = true;
                    break;
                }
                op2 = pop(stack);
                if (op2 == ERR) {
                    error = true;
                    break;
                }
                res = op2 < 0? -(abs(op2) % abs(op1)) : abs(op2) % abs(op1);
                if (MAX < abs(res)) {
                    error = true;
                    break;
                }
                stack.push_back(res);
                break;
        }
        if (error) break;
    }
    
    if (error || stack.size() != 1) printf("%s", "ERROR\n");
    else printf("%d\n", stack.back());
}
int main() {
    char command[5];
    int num, N, V;

    while(true) {
        vector<int> machine;
        for (int i=0; i<100000; i++) {
            scanf("%s", command);
            if (!strncmp(command, "QUIT", 1)) return 0;
            else if (!strncmp(command, "END", 1)) break;
            else if (!strncmp(command, "NUM", 1)) {
                scanf("%d", &num);
                machine.push_back(NUM);     // machine command가 NUM이면 그 다음에 있는 숫자 사용
                machine.push_back(num);
            }
            else if (!strncmp(command, "POP", 1)) machine.push_back(POP);
            else if (!strncmp(command, "INV", 1)) machine.push_back(INV);
            else if (!strncmp(command, "DUP", 2)) machine.push_back(DUP);
            else if (!strncmp(command, "SWP", 2)) machine.push_back(SWP);
            else if (!strncmp(command, "ADD", 1)) machine.push_back(ADD);
            else if (!strncmp(command, "SUB", 2)) machine.push_back(SUB);
            else if (!strncmp(command, "MUL", 2)) machine.push_back(MUL);
            else if (!strncmp(command, "DIV", 2)) machine.push_back(DIV);
            else if (!strncmp(command, "MOD", 2)) machine.push_back(MOD);
        }
        scanf("%d", &N);
        for (int i=0; i<N; i++) {
            scanf("%d", &V);
            sol(V, machine);
        }
        printf("\n");
    }
}