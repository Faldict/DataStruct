#include <iostream>
using namespace std;
 
int a[100000];
 
void f1(int n) {
    long long time[3] = {0, 0, 0};
    long long wait = 0;
    for (int i=0; i < n; i++) {
        wait += time[i % 3];
        time[i % 3] += a[i];
    }
    long long cost = 0;
    for (int i=0; i<3; i++) {
        if (time[i] > cost) cost = time[i];
    }
    cout<<wait<<" "<<cost<<endl;
}
 
void f2(int n) {
    long long time[3] = {0, 0, 0};
    long long cost = 0;
    long long wait = 0;
    int tmp;
    for (int i=0; i<n; i++) {
        if (time[0] < time[1] && time[0] < time[2]) tmp = 0;
        else if (time[1] < time[2]) tmp = 1;
        else tmp = 2;
        wait += time[tmp];
        time[tmp] += a[i];
        cost = max(cost, time[tmp]);
    }
    cout<<wait<<" "<<cost<<endl;
}
 
int main() {
    int n;
    cin>>n;
    for (int i=0; i<n; i++) {
        cin>>a[i];
    }
    f1(n);
    f2(n);
    return 0;
}