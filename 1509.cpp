#include <iostream>
#include <cstdio>
using namespace std;

int months[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool isYear (int y) {
	if (y % 400 == 0) return true;
	if (y % 4 == 0 && y % 100 != 0) return true;
	return false;
} 

int calcFirstDay (int m, int y) {
	int days = 0;
	for (int i=1850; i<y; i++) {
		if (isYear(i)) days += 366;
		else days += 365;
	}
	for (int i=1; i<m; i++) {
		days += months[i];
	}
	if (isYear(y) && m > 2) days++;
	int day = (days + 2) % 7;
	return day == 0 ? 7 : day;
}

int maxDay(int m, int y) {
	if (isYear(y) && m == 2) { return 29; }
	return months[m];
}

void calcDay(int a, int b, int c, int y) {
	int first = calcFirstDay(a, y);
	int d = c >= first ? (b - 1) * 7 + c - first + 1 : b * 7 + c - first + 1;
	if (d <= maxDay(a, y) && d > 0) {
		printf("%04d/%02d/%02d\n", y, a, d);
	} else {
		cout<<"none"<<endl;
	}
}

int main() {
	int a, b, c, y1, y2;
	cin>>a>>b>>c>>y1>>y2;
	for (int y=y1; y<=y2; y++) calcDay(a, b, c, y);
	return 0;
}