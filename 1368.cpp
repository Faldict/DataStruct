#include <iostream>
using namespace std;

int monkeys[10000];

int main() {
	int n, m;
	cin>>n>>m;
	for (int i=0; i<n; i++) monkeys[i] = i+1;
	int flag, k, w;
	int now=0;
	for (int i=0; i<m; i++) {
		cin>>flag;
		if (flag) {
			cin>>k>>w;
			now = (now + k) % n;
			for (int j=n; j>now; j--) monkeys[j] = monkeys[j-1];
			monkeys[now] = w;
			n++;
		}
		else {
			cin>>k;
			now = (now + k - 1) % n;
			for (int j=now; j<n; j++) monkeys[j] = monkeys[j+1];
			n--;
		}
	}

	int sum=0;
	for (int i=0; i<n; i++) {
		sum+=monkeys[i];
	} 
	cout<<sum<<endl;
	return 0;
}