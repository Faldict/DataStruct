#include <iostream>
using namespace std;

int dict[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

int num2tee(int num) {
	if (num == 0) return 6;
	int tee = 0;
	while (num > 0) {
		tee += dict[num % 10];
		num /= 10;
	}
	return tee;
}

int main() {
	int n;
	cin>>n;

	int count = 0;
	int A = 1111;
	while (A >= 0) {
		int B = A;
		while (B >= 0) {
			int C = A - B;
			if (num2tee(A) + num2tee(B) + num2tee(C) + 3 == n) {
				count++;
				// cout<<A<<"-"<<B<<"="<<C<<endl;
			}
			B--;
		}
		A--;
	}
	cout<<count<<endl;
	return 0;
}