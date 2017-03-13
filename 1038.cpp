#include <iostream>
using namespace std;

int main()
{
    int m;
    int head = 0;
    cin>>m;
    int *monkeys = new int [m];
    for(int i=0; i<m; i++) monkeys[i] = i + 1;
    for (int i=0; i<m-1; i++) {
        int k;
        cin>>k;
        int t = (k + head) % (m - i) - 1;
        if (t < 0) t = m - i - 1;
        for (int j=t; j<m-i-1; j++) {
            monkeys[j] = monkeys[j+1];
        }
        head = t;
    }
    cout<<monkeys[0]<<endl;
    return  0;
}