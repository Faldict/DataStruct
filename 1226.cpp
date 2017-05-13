#include <iostream>
using namespace std;

void qsort(int *begin, int *end) {
	if (end - begin <= 1) return;
	int head = *begin; size_t before = 0;
	for (int *p = begin + 1; p != end; ++p) {
		if (*p <= *begin) before++;
	}
	swap(*begin, *(begin + before));
	size_t i = 0, j = before + 1;
	while (i < before && j < end - begin) {
		while (*(begin + i) <= *(begin + before)) i++;
		while (*(begin + j) > *(begin + before)) j++;
		if (i < before && j < end - begin) swap(*(begin + i), *(begin + j));
	}

	qsort(begin, begin + before);
	qsort(begin + before + 1, end);
}

int main() {
	int n;
	cin>>n;
	int *arr = new int [n];
	for (int i = 0; i < n; i++) cin>>arr[i];
	qsort(arr, arr + n);
	for (int i = 0; i < n; i++) cout<<arr[i]<<" ";
	cout<<endl;
	return 0;
}