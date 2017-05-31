#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#define MAX_INT 2147483647;
using namespace std;

int n, m, start, e;
int dist[10010];
bool arrive[10010];
int previous[10010];

int main() {
	cin>>n>>m>>start>>e;
	vector<vector<pair<int, int> > > graph(n+1);
	for (int i=0; i<m; i++) {
		int a, b, p;
		scanf("%d %d %d", &a, &b, &p);
		graph[a].push_back(pair<int, int>(b, p));
	}
	for (int i=1; i<=n; i++) dist[i] = MAX_INT;
	dist[start] = 0;
	
	queue<int> q;
	q.push(start);
	while (!q.empty()) {
		int p = q.front();
		q.pop();
		arrive[p] = true;
		for (int i=0; i<graph[p].size(); i++) {
			pair<int, int> next = graph[p][i];
			if (dist[p] + next.second < dist[next.first]) {
				dist[next.first] = dist[p] + next.second;
				previous[next.first] = p;
			}
			if (!arrive[next.first]) q.push(next.first);
		}
	}
	for (int p=1; p<=n; p++)
		for (int i=0; i<graph[p].size(); i++) {
			pair<int, int> next = graph[p][i];
			if (dist[p] + next.second < dist[next.first]) {
				dist[next.first] = dist[p] + next.second;
				previous[next.first] = p;
			}
	}
	cout<<dist[e]<<endl;
	vector<int> path; path.push_back(e);
	int p = e;
	while (p != start) {
		p = previous[p];
		path.push_back(p);
	}
	for (int i=path.size()-1; i>=0; i--) printf("%d ", path[i]);
	printf("\n");
	return 0;
}