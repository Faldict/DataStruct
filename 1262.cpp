#include <iostream>
using namespace std;

int n;
int timeline[1000000];
int begin_time = 1000000;
int end_time = 0;

int main() {
	cin>>n;
	int a, b;
	for (int i=0; i<n; i++) {
		cin>>a>>b;
		timeline[a]++;
		timeline[b]--;
		begin_time = a < begin_time ? a : begin_time;
		end_time = b > end_time ? b : end_time;
	}

	int num = 0;
	int tmp_zero = 0, tmp_one = 0, res_zero = 0, res_one = 0;
	bool state = false;
	for (int i = begin_time; i <= end_time; i++) {
		num += timeline[i];
		if (num > 0) {
			if (state) tmp_one++;
			else {
				res_zero = max(tmp_zero, res_zero);
				tmp_one = 1;
				state = true;
				tmp_zero = 0;
			}
		}
		else {
			if (state) {
				res_one = max(tmp_one, res_one);
				tmp_zero = 1;
				state = false;
				tmp_one = 0;
			}
			else tmp_zero++;
		}
	}

	cout<<res_one<<" "<<res_zero<<endl;
	return 0;
}