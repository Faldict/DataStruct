#include <iostream>
#include <cstring>
using namespace std;

char* HighMul(char *a, char *b) {
    int l1 = strlen(a), l2 = strlen(b);
    int l = l1 + l2;
    char *c = new char [l];
    memset(c, '0', l);
    int tmp;
    for (int i=l1-1; i>=0; i--) {
        for (int j=l2-1; j>=0; j--) {
            tmp = (a[i] - '0') * (b[j] - '0') + c[i+j+1] - '0';
            c[i+j] += tmp / 10;
            c[i+j+1] = tmp % 10 + '0';
        }
    }
    if (c[0] == '0') c++;
    return c;
}

int main() {
    char a[1000], b[1000];
    cin>>a;
    cin>>b;
    cout<<HighMul(a, b)<<endl;
    return 0;
}