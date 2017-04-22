#include <iostream>
#include <string.h>

using namespace std;

int bestack[10000];
int ifstack[10000];

int besp = 0;
int iesp = 0;

void push(int *stack, int flag, int *esp) {
    stack[++(*esp)]  = flag;
}

int pop(int *stack, int *esp) {
    if (esp == 0) return -1;
    return stack[(*esp)--];
}

int main() {
    char line[10000];
    bool res = true;
    
    while (cin>>line) {

        if (strcmp(line, "begin") == 0) push(bestack, 1, &besp);
        else if (strcmp(line, "end") == 0) {
            if (pop(bestack, &besp) != 1) {
                res = false;
                break;
            }
        }
        else if (strcmp(line, "if") == 0) {
            push(ifstack, 1, &iesp);
        } 
        else if (strcmp(line, "then") == 0) {
            push(ifstack, 2, &iesp);
        }
        else if (strcmp(line, "else") == 0) {
            if (pop(ifstack, &iesp) != 2) {
                res = false;
                break;
            }
            if (pop(ifstack, &iesp) != 1) {
                res = false;
                break;
            }
        }
    }

    int c;
    while (c = pop(ifstack, &iesp) != -1) {
        if (c == 2) 
            if (pop(ifstack, &iesp) != 1) {
                res = false;
                break;
            }
        else {
            res = false;
            break;
        }
    }

    if (res && besp == 0) {
        cout<<"Match!"<<endl;
    }
    else cout<<"Error!"<<endl;
    return 0;
}