#include <iostream>
using namespace std;

void merge(int* a, int* b, size_t m, size_t n) {
	size_t i = 0, j = 0;
	while (i < m && j < n) {
		if (a[i] < b[j]) cout<<a[i++]<<" ";
		else cout<<b[j++]<<" ";
	}
	while(i < m) {
		cout<<a[i++]<<" ";
	}
	while(j < n) {
		cout<<b[j++]<<" ";
	}
	cout<<endl;
}

int main() {
	int m, n;
	cin>>m>>n;
	int *a = new int [m];
	for (int i = 0; i < m; i++) cin>>a[i];
	int *b = new int [n];
	for (int j = 0; j < n; j++) cin>>b[j];
	merge(a, b, m, n);
	return 0;
}