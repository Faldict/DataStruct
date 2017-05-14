#include <iostream>
#include <algorithm>

using namespace std;

int m, s, c;
int a[210];
int b[210];

int main() {
    cin>>m>>s>>c;
    for (int i = 0; i < c; i++) cin>>a[i];
    // the input is not sorted???
    sort(a, a + c);
    
    int min_length = a[c-1] - a[0] + 1;

    for (int i = 0; i < c - 1; i++) b[i] = a[i + 1] - a[i] - 1;
    sort(b, b + c -1);
    
    if (m > c) m = c;
    for (int j = 0; j < m - 1; j++) {
        min_length -= b[c - j - 2];
    }
    cout<<min_length<<endl;
    return 0;
}