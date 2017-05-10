#include "cstdio"
#include <iostream>
using namespace std;

int degree1[110];
int degree2[110];

int tree1[110];
int tree2[110];

int total_test_samples;
int n, m;

void init() {
	for (int i=0; i < 110; i++) {
		degree1[i] = degree2[i] = tree1[i] = tree2[i] = 0;
	}
}

int main() {
	cin>>total_test_samples;
	int x, y;
	while (total_test_samples-- > 0) {
		init();
		cin>>n;
		for (int i=0; i<n; i++) {
			cin>>x>>y;
			degree1[x]++; degree1[y]++;
			tree1[x] ^= y; tree1[y] ^= x;
		}
		cin>>m;
		for (int i=0; i<m; i++) {
			cin>>x>>y;
			degree2[x]++; degree2[y]++;
			tree2[x] ^= y; tree2[y] ^= x;
		}
		if (n > m)
			printf("NO\n");
		else 
			printf("YES\n");
	}

	return 0;
}