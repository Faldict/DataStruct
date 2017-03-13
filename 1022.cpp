#include <iostream>
using namespace std;

// Author: Faldict
// Date: 2017-03-12
// fibnacci mod 2010 array has a period of 2040 

int fib(int n) {
    if(n==0) return 0;
    if(n<=2) return 1;
 
    int a=1, b=1, c;
    for (int i=0; i<n-2; i++) {
        c = (a + b) % 2010;
        a = b;
        b = c;
    }
    return b;
}
 
int main() {
    long long n;
    cin>>n;
    cout<<fib(n % 2040)<<endl;
}