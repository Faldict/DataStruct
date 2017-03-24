#include <iostream>
#include <cstring>
using namespace std;
 
// + = 43
// - = 45
// * = 42
// / = 47
// ( = 40
// ) = 41
 
char expression[1000];
 
int parse(int head, int tail) {
    while (expression[head] == ' ') head++;
    while (expression[tail-1] == ' ') tail--;
    if (expression[head] == 40 && expression[tail-1] == 41) {
        head++; tail--;
    }
    int quote = 0; char c;
    for (int i=head; i<tail; i++) {
        c = expression[i];
        if (c == 40) quote++;
        else if (c == 41) quote--;
        else if ((c == 43 || c == 45) && (quote == 0)) return i;
    }
    for (int i=head; i<tail; i++) {
        c = expression[i];
        if (c == 40) quote++;
        else if (c == 41) quote--;
        else if ((c == 42 || c == 47) && (quote == 0)) return i;
    }
    return tail;
}
 
int operate(char opt, int left, int right) {
    switch (opt) {
        case 43: return left + right;
        case 45: return left - right;
        case 42: return left * right;
        case 47: return left / right;
    }
}
 
int asciiOrder(int head, int mid, int tail) {
    while (expression[head] == ' ') head++;
    while (expression[tail-1] == ' ') tail--;
    if (expression[head] == 40 && expression[tail-1] == 41) {
        head++; tail--;
    }
    // check if it is a single charactor
    if (head >= tail + 1 || mid >= tail) {
        int res = 0;
        for (int i=head; i<tail; i++) {
            res = res * 10 + (expression[i] - '0');
        }
        return res;
    };
 
    int midl = parse(head, mid);
    int midr = parse(mid+1, tail);
    int left = asciiOrder(head, midl, mid);
    int right = asciiOrder(mid+1, midr, tail);
 
    char midTmp = expression[mid];
    for (int i=mid; i>head+1; i--) {
        expression[i] = expression[i-2];
    }
    expression[head] = midTmp;
    expression[head+1] = ' ';
 
    return operate(midTmp, left, right);
}
 
int main() {
    cin.getline(expression, 1000);
    int tail = strlen(expression);
    int mid = parse(0, tail);
    int result = asciiOrder(0, mid, tail);
    cout<<expression<<endl;
    cout<<result<<endl;
    return 0;
}