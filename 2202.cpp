#include <cstdio>
#include <iostream>

using namespace std;

int n, m;
int field[1010][1010];
bool mark[1010][1010];

void input() {
	scanf("%d %d", &n, &m);
	for (int i=1; i<=n; i++) {
		for (int j=1; j<=m; j++) {
			scanf("%d", &field[i][j]);
			mark[i][j] = true;
		}
	}
}

bool notReach(int x, int y) {
	return x > 0 && y > 0 && x <= n && y <= m && mark[x][y];
}

bool arrive(int x, int y, int per) {
	// cout<<x<<" "<<y<<endl;
	if (x == n && y == m) return true;
	per = per + field[x][y];
	if (per > 1) return false;
	mark[x][y] = false;
	bool r1, r2, r3, r4;
	if (notReach(x, y+1)) {
		if (arrive(x, y+1, per)) return true;
	}
	if (notReach(x, y-1)) {
		if (arrive(x, y-1, per)) return true;
	}
	if (notReach(x - 1, y )) {
		if (arrive(x - 1, y, per)) return true;
	}
	if (notReach(x + 1, y)) {
		if (arrive(x + 1, y, per)) return true;
	}

	return false;
}
 
int main() {
	int k;
	cin>>k;
	for (int i = 0; i < k; i++) {
		input();
		cout<<arrive(1, 1, 0)<<endl;
	}
}