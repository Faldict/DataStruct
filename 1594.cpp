#include "cstdio"
using namespace std;

int n, m, q;

int main() {
	scanf(" %d%d%d", &n, &m, &q);
	int **a = new int *[n+1];
	long long **s = new long long *[n+1];
	for (int i=0; i<n+1; i++) {
		a[i] = new int [m+1];
		s[i] = new long long [m+1];
	}


	for (int i=1; i<=n; i++) for (int j=1; j<=m; j++) {
		scanf(" %d", &a[i][j]);
	}

	s[0][0] = 0;
	for (int i=0; i<=n; i++) s[i][0] = 0;
	for (int j=1; j<m+1; j++) s[0][j] = 0;

	for (int i=1; i<=n; i++) for (int j=1; j<=m; j++) {
		s[i][j] = s[i-1][j] + s[i][j-1] - s[i-1][j-1] + a[i][j];
	} 

	for (int i=0; i<q; i++) {
		int x1, x2, y1, y2;
		scanf(" %d%d%d%d", &x1, &y1, &x2, &y2);
		long long res = s[x2][y2] + s[x1-1][y1-1] - s[x1-1][y2] - s[x2][y1-1];
		printf("%lld\n", res);
	}
	return 0;
}