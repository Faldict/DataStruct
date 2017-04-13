#include <cstdio>
#include <iostream>
#include <map>
 
using namespace std;
 
int milk[100000];
int maxl = 0;
 
map<int, int> sequence;
 
int main() {
    int n, k;
    scanf(" %d%d", &n, &k);
    for (int i=0; i<n; i++) {
        scanf(" %d", &milk[i]);
    }
    
    int i=0;
    int p = i + 1;
    int kind  = 1;
    int head = milk[i];
    sequence[head] = 1;
    while (p < n) {
        head = milk[i];
        while (kind <= k + 1 && p < n) {
            if (milk[p] == head) {
                sequence[head]++;
            }
            else { 
                if (sequence.find(milk[p]) != sequence.end()) {
                    sequence[milk[p]]++;
                }
                else {
                    sequence[milk[p]] = 1;
                    kind++;
                }
            }
            p++;
        }
 
        maxl = sequence[head] > maxl ? sequence[head] : maxl;
        while (milk[i+1] == head) { i++; sequence[head]--;}
        ++i; sequence[head]--;
        if (sequence[head] == 0) {
            kind--;
            sequence.erase(head);
        }
    }

    map<int, int>::iterator it;
    for (it = sequence.begin(); it != sequence.end(); ++it) {
        maxl = it->second > maxl ? it->second : maxl;
    }
 
    printf("%d\n", maxl);
    return 0;
}