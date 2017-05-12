#include <iostream>
using namespace std;
#define MAX_N 110

int t, n, m;
int graph[MAX_N][MAX_N];

void findSubgraph() {
    for (int i = 1; i <= n; i++) {
        if (graph[i][0] > 0) {
            int next = graph[i][1];
            for (int j = 1; j <= graph[i][0]; j++) {
                if (graph[i][j] < next) next = graph[i][j];
            }
            cout<<2<<" "<<i<<" "<<next<<endl;
            return;
        }
    }
}

void input() {
    cin>>n>>m;
    for (int i = 1; i <= n; i++) {
        graph[i][0] = 0;
    }
    int u, v;
    for (int i = 0; i < m; i++) {
        cin>>u>>v;
        graph[u][++graph[u][0]] = v;
        graph[v][++graph[v][0]] = u;
    }
}

void output() {
    if (m == 0) {
        cout<<"NO ODD SUBGRAPH"<<endl;
        return;
    }

    for (int i = 1; i <= n; i++) {
        if (graph[i][0] % 2 == 0) {
            findSubgraph();
            return;
        }
    }
    cout<<"ODD GRAPH"<<endl;
}

int main() {
    cin>>t;
    for (int i = 0; i < t; i++) {
        input();
        output();
    }
    return 0;
}