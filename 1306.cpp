#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

float h[510], r[510];

int main() {
	int n;
	float alpha;
	cin>>n>>alpha;

	float left = 0.0, right = 100.0, radius = 0.0, mid;
	cin>>h[0];
	for (int i=1; i<=n; i++) {
		float tmp;
		cin>>tmp;
		h[i] = h[i-1] + tmp;
	}

	float x = tan(alpha);
	for (int i=0; i<=n-1; i++) {
		cin>>r[i];

		if (r[i] > radius) {
			radius = r[i];
			mid = h[i] / x;
		};

		float minus = h[i] / x;
		left = max(r[i] + minus, left);
		right = min(minus - r[i], right);
	}

	float top = h[n] / x;
	// cout<<left<<" "<<mid<<" "<<right<<endl;

	float s = top > left ? (M_PI * (mid - right) + 2 * (top - mid)) * radius / 2 : M_PI * radius * (left - right) / 2;
	printf("%.2f\n", s);
	return 0;
}