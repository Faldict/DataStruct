#include <cstdio>
 
using namespace std;
 
struct pos {
    int x;
    int y;
    pos() : x(0), y(0) {};
    pos(int a, int b) : x(a), y(b) {};
} *hpt[500];
 
int gnum = 0;
int hnum = 0;
 
int gpt[500][2];
 
int number=0, area=1000000;
 
int max(int a, int b, int c, int d) {
    int res1 = a > b ? a : b;
    int res2 = c > d ? c : d;
    int res = res1 > res2 ? res1 : res2;
    return res;
}
 
void find(pos* space[], int total,  int left, int right, int down, int up, int start) {
    if (total < number) return;
    if (start < gnum) {
        if (gpt[start][0] >= left && gpt[start][0] <= right && gpt[start][1] >= down && gpt[start][1] <= up) {
            int x = gpt[start][0], y = gpt[start][1];
            pos *hl[total], *hr[total], *hu[total], *hd[total];
            int nl = 0, nr = 0, nu = 0, nd = 0;
            for (int i=0; i<total; i++) {
                if (space[i]->x < x) hl[nl++] = space[i];
                else if (space[i]->x > x) hr[nr++] = space[i];
                if (space[i]->y < y) hd[nd++] = space[i];
                else if (space[i]->y > y) hu[nu++] = space[i];
            }
 
            if (x > left) find(hl, nl, left, x-1, down, up, start+1);
            if (x < right) find(hr, nr, x+1, right, down, up, start+1);
            if (y < up) find(hu, nu, left, right, y+1, up, start+1);
            if (y > down) find(hd, nd, left, right, down, y-1, start+1);
        }
        else find(space, total, left, right, down, up, start+1);
        return;
    }
    
    int num = 0;
    int x1 = right, x2 = left, y1 = up, y2 = down;
    int x,y;
 
    for (int i=0; i<total; i++) {
        x = space[i]->x; y = space[i]->y;
        x1 = x < x1 ? x : x1;
        x2 = x > x2 ? x : x2;
        y1 = y < y1 ? y : y1;
        y2 = y > y2 ? y : y2;
        num++;   
    }
 
    int tmp_area = (y2 - y1) * (x2 - x1);
    if (num > number) {
        number = num;
        area = tmp_area;
    } else if (num == number && area > tmp_area) {
        area = tmp_area;
    }
}
 
int main() {
    int n;
    scanf("%d", &n);
 
    int x, y; char flag;
    for (int i=0; i<n; i++) {
        scanf(" %d %d %c", &x, &y, &flag);
        if (flag == 'H') {
            hpt[hnum++] = new pos(x, y);
        }
        else {
            gpt[gnum][0] = x;
            gpt[gnum++][1] = y;
        }
    }
 
    find(hpt, hnum, 0, 1000, 0, 1000, 0);
    printf("%d %d\n", number, area);
    return 0;
}