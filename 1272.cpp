#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> numbers;

int main() {
	int n;
	cin>>n;
	for (int i=0; i<n; i++) {
		int number;
		cin>>number;
		numbers.push_back(number);
	}
	int i=1;
	for (int i=0; i<numbers.size(); i++) {
		int x = numbers[i];
		for (int j=0; j<i; j++) {
			int y = numbers[j];
			int z = max(x, y) / min(x, y);
			if (find(numbers.begin(), numbers.end(), z) == numbers.end()) {
				numbers.push_back(z);
			}
		}
	}
	cout<<numbers.size()<<endl;
	return 0;
}