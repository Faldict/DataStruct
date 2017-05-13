#include <iostream>
#include <cstdio>
#include <algorithm>
#define MAX_N 100010
using namespace std;

typedef pair<int, int> paint;

paint activity[MAX_N];
int number[MAX_N];

bool cmp(paint a, paint b) {
	if (a.first == b.first) return a.second < b.second;
	return a.first < b.first;
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i=0; i<n; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		activity[i] = paint(a, b);
	}
	sort(activity, activity + n, cmp);
	
	int ma = 1;
	for (int i=0; i<n; i++) {
		int j = i - 1;
		while (activity[j].second > activity[i].first && j >= 0) j--;
		if (j < 0) number[i] = 1;
		else number[i] = number[j] + 1;
		// cout<<activity[i].first<<" "<<activity[i].second<<" "<<number[i]<<endl;
		ma = max(number[i], ma);
	}
	cout<<ma<<endl;
	return 0;
}