#include <iostream>
using namespace std;

int cycle[2017];
int sum[2017];

int main() {
    int n;
    cin>>n;
    sum[0] = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> cycle[i];
        sum[i] = cycle[i] + sum[i - 1];
    }
    int half = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j < i; ++j) {
            if (2 * (sum[i] - sum[j]) == sum[n]) half++; 
        }
    }
    cout << half * (half - 1) / 2 << endl;
    return 0;
}