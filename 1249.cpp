#include <iostream>
using namespace std;

pair<int, int> d[10000];
int top = 0;

bool gcd(int a, int b) {
	int m = min(a, b);
	int d = 1;
	for (int i=1; i<=m; i++) {
		if (a % i == 0 && b % i == 0) d = i;
	}
	if (d > 1) return false;
	return true;
}

int main() {
	int n;
	cin>>n;

	d[top++] = pair<int, int>(0, 1);
	d[top++] = pair<int, int>(1, 1);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j < i; j++) {
			if (gcd(j, i)) {
				float now = float(j) / float(i);
				for (int k = 0; k < top; k++) {
					float tmp = float(d[k].first) / float(d[k].second);
					if (tmp > now) {
						for (int l = top; l > k; l--) {
							d[l] = d[l-1];
						}
						d[k] = pair<int, int>(j, i);
						top++;
						break;
					}
				}
			}
		}
	}

	for (int i = 0; i < top; i++) {
		cout<<d[i].first<<'/'<<d[i].second<<endl;
	}
	return 0;
}