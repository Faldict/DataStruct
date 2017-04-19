#include <iostream>
using namespace std;

int tree[10000];

int main() {
	int m, l;
	cin>>l>>m;
	for (int i=0; i<=l; i++) tree[i] = 1;
	for (int i=0; i<m; i++) {
		int a, b;
		cin>>a>>b;
		for (int j=a; j<=b; j++) tree[j] = 0;
	}
	int s = 0;
	for (int i=0; i<=l;i++) s += tree[i];
	cout<<s<<endl;
	return 0;
}