#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

struct milk {
	int x;
	int h;
	milk() : x(0), h(0) {};
	milk(int a, int b) : x(a), h(b) {};
};

int cmp(const void* a, const void* b) {
	return (*(milk *)a).x > (*(milk *)b).x ? 1 : -1;
}

int main() {
	int n, d;
	scanf(" %d%d", &n, &d);

	milk * milks = new milk [n];

	int mh = 0; 
	int x, h;
	for (int i=0; i<n; i++) {
		scanf(" %d%d", &x, &h);
		milks[i] = milk(x, h);
		mh = (milks + i)->h > mh ? (milks + i)->h : mh;
	}

	qsort(milks, n, sizeof(milks[0]), cmp);


	int num = 0;
	bool left, right;

	for (int i=1; i<n-1; i++) {
		if ( 2 * (milks + i)->h > mh) continue;

		left = right = false;

		for (int j=i-1; j>=0; --j) {
			if ((milks + i)->x - (milks + j)->x <= d && (milks + j)->h >= (milks + i)->h * 2) { 
				left = true; 
				break; 
			}
			else if ((milks + i)->x - (milks + j)->x > d) break;
		}
		for (int j=i+1; j<n; j++) {
			if ((milks + j)->x - (milks + i)->x <= d && (milks + j)->h >= (milks + i)->h * 2) {
				right = true;
				break;
			}
			else if ((milks + j)->x - (milks + i)->x > d) break;
		}

		if (left && right) num++;
	}
	
	printf("%d\n", num);
	return 0;
}