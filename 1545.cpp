#include <cstdio>
#include <stack>
using namespace std;

struct data {
	int x;
	int y;
	int r;
	char color;
	data(int _x, int _y, int _r, char _color) : x(_x), y(_y), r(_r), color(_color) {};
};

data *circles[10000];
 
int main() {
	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);
	int x, y, r;
	char color;

	for (int i=0; i<k; i++) {
		scanf("%d %d %d %c", &x, &y, &r, &color);
		circles[i] = new data(x, y, r, color);
	}

	int red = 0, green = 0, blue = 0;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			for (int t = k - 1; t >= 0; t--) {
				data* tmp = circles[t];
				if ((i - tmp->x) * (i - tmp->x) + (j - tmp->y) * (j - tmp->y) <= tmp->r * tmp->r) {
					if (tmp->color == 'R') {
						red++;
					}
					else if (tmp->color == 'G') {
						green++;
					}
					else {
						blue++;
					}
					break;
				}
			}
		}
	}
 
	printf("Red:%d\n", red);
	printf("Green:%d\n", green);
	printf("Blue:%d\n", blue);
 
	return 0;
}