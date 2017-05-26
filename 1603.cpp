#include <iostream>
#include <cstdio>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	int* arr = new int[n];
	int* num = new int[n];
	for (int i=0; i<n; i++) scanf("%d", &arr[i]);
	int p = n - 1; num[p] = 0;
	while (--p >= 0) {
		int tmp = 0;
		for (int i = p + 1; i < n; i++) {
			if (arr[p] > arr[i]) tmp++;
		}
		num[p] = tmp;
	}
	for (int i=0; i<n; i++) printf("%d ", num[i]);
	printf("\n");
	return 0;
}