#include <iostream>
using namespace std;
#define MAX_N 110

int student[MAX_N];
int inc[MAX_N];
int desc[MAX_N];

int main() {
	int n;
	cin>>n;
	for (int i =1; i<=n; i++) {
		cin>>student[i];
	}

	// bound condition
	student[0] = student[n+1] = -1;
	    inc[0] =     inc[n+1] =  0;
	   desc[0] =    desc[n+1] =  0;

	// INCREASE
	for (int i = 1; i <= n; i++) {
		int k = 0;
		for (int j = 1; j < i; j++) if (student[j] < student[i] && k < inc[j]) k = inc[j];
		inc[i] = k + 1;
	}

	// DECREASE
	for (int i = n; i > 0; i--) {
		int k = 0;
		for (int j = n; j > i; j--) if (student[j] < student[i] && k < desc[j]) k = desc[j];
		desc[i] = k + 1; 
	}

	int maxk = 0;
	for (int i = 1; i <= n; i++) {
		maxk = max(maxk, inc[i] + desc[i] - 1);
	}

	cout << n - maxk << endl;
	return 0;
}