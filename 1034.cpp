#include <iostream>
#include <cstdio>

using namespace std;

int main() {
    int n, k;
    cin>>n>>k;
    int * link = new int [n+k];
    for (int i=0; i<n; i++) scanf("%d", &link[i]);
    for (int i=0; i<k; i++) link[i+n] = link[i];

    int qm = 1000000000;
    int th=0, tt, tm, i;
    while(th < n) {
        tt = th + k;
        tm = 0;
        for (i=th; i<tt; ++i) {
            if (link[i] >= tm) { 
                tm = link[i];
                th = i + 1;
                if (tm >= qm) break; 
            }
        }
        if (tm < qm) qm = tm;
    }
    cout<<qm<<endl;
    return 0;  
}