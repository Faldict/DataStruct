#include <iostream>
#include <vector>
#include <queue>
#define MAX_INT 2147483647;
using namespace std;
 
int n, m, start, e;
int dist[15];
bool arrive[15];
 
int main() {
	cin>>n>>m>>start>>e;
	vector<vector<pair<int, int> > > graph(n+1);
	for (int i=0; i<m; i++) {
		int a, b, p;
		cin>>a>>b>>p;
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
			if (dist[p] + next.second < dist[next.first]) dist[next.first] = dist[p] + next.second;
			if (!arrive[next.first]) q.push(next.first);
		}
	}
	for (int p=1; p<=n; p++) {
		for (int i=0; i<graph[p].size(); i++) {
			pair<int, int> next = graph[p][i];
			if (dist[p] + next.second < dist[next.first]) dist[next.first] = dist[p] + next.second;
		}
	}
	for (int p=1; p<=n; p++) {
		for (int i=0; i<graph[p].size(); i++) {
			pair<int, int> next = graph[p][i];
			if (dist[p] + next.second < dist[next.first]) dist[next.first] = dist[p] + next.second;
		}
	}
	cout<<dist[e]<<endl;
	return 0;
}