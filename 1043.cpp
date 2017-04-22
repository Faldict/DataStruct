#include <iostream>
using namespace std;

int n;
bool wq = true;


int tree[5000000];
int pos[5000000];

int main() {
	cin>>n;
	for (int i=1; i < n; i++) tree[i] = false;

	int father;
	for (int i=1; i <= n-1; i++) {
		cin>>father;
		int son = pos[father]<<1;
		if (son > n) wq = false;
		else if (tree[son + 1] > 0) {
			tree[son + 2] = i;
			pos[i] = son + 2;
		}
		else {
			tree[son + 1] = i;
			pos[i] = son + 1;
		}
	}

	if (wq) {
		for (int i=1; i < n; i++) {
			if (tree[i] == 0) {
				wq = false;
				break;
			}
		}
	}

	if (wq) cout<<"true"<<end_timel;
	else cout<<"false"<<end_timel;

	return 0;
}