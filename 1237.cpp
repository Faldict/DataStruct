#include <cstdio>
#include <vector>
#include <iostream>
using namespace std;
 
int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int *degree = new int[n+1];
    int *seq = new int[n+1];
    for (int i = 0; i <= n; i++) {
        seq[i] = 0;
        degree[i] = 0;
    }
    vector<vector<int> > graph(n+1);
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        degree[a]++;
        graph[b].push_back(a);
    }
    vector<int> backend(0);
    for (int i = 1; i <= n; i++) {
        if (degree[i] == 0) {
            backend.push_back(i);
        }
    }
    int max_len = 0;
    while (!backend.empty()) {
        max_len = max_len < seq[backend[0]] ? seq[backend[0]] : max_len;
        for (size_t i = 0; i < graph[backend[0]].size(); i++) {
            int c = graph[backend[0]][i];
            degree[c]--;
            if (degree[c] == 0) backend.push_back(c);
            seq[c] = seq[backend[0]] + 1;
        }
        backend.erase(backend.begin());
    }

    cout<< max_len + 1 << endl;
    return 0;
}