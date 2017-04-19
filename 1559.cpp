#include <cstdio>
 
using namespace std;

// define the struct to record H type points.
// x : x coordinate
// y : y coordinate
// hpt : store all the H type points. It is a pointer array.
struct pos {
    int x;
    int y;
    pos() : x(0), y(0) {};
    pos(int a, int b) : x(a), y(b) {};
} *hpt[500];

// gnum record G type points' amount
// hnum record H type points' amount
int gnum = 0;
int hnum = 0;

// gpt is a matrix record G type points' coordinates
int gpt[500][2];
 
// number : the max H type points' number a square can have
// area : the min area of the square in this case 
int number=0, area=1000000;

// find : recursion function
// space : the array of H type points
// total : size of space, also the H type points' number in the space
// left, right, down, up : the border
// start : the current G point's number
void find(pos* space[], int total,  int left, int right, int down, int up, int start) {
    // prune if the space's H type points' number is less than present `number`
    if (total < number) return;

    // check if there's G points in the queue
    if (start < gnum) {
        // check if this G point is in the space
        if (gpt[start][0] >= left && gpt[start][0] <= right && gpt[start][1] >= down && gpt[start][1] <= up) {
            // the G points' coordinate
            int x = gpt[start][0], y = gpt[start][1];

            // allocate new spaces : left, right, up and down
            pos *hl[total], *hr[total], *hu[total], *hd[total];
            int nl = 0, nr = 0, nu = 0, nd = 0;

            // iteration to divide points into these spaces
            for (int i=0; i<total; i++) {
                if (space[i]->x < x) hl[nl++] = space[i];
                else if (space[i]->x > x) hr[nr++] = space[i];
                if (space[i]->y < y) hd[nd++] = space[i];
                else if (space[i]->y > y) hu[nu++] = space[i];
            }
            
            // divide to four spaces and find recursively
            if (x > left) find(hl, nl, left, x-1, down, up, start+1);
            if (x < right) find(hr, nr, x+1, right, down, up, start+1);
            if (y < up) find(hu, nu, left, right, y+1, up, start+1);
            if (y > down) find(hd, nd, left, right, down, y-1, start+1);
        }
        // the number of G step forward
        else find(space, total, left, right, down, up, start+1);
        return;
    }
    
    // init x1, x2, y1, y2
    // x1 : left border of the min rect
    // x2 : right border of the min rect
    // y1 : down border of the min rect
    // y2 : up border of the min rect
    // x, y : tmp coordinates
    int x1 = right, x2 = left, y1 = up, y2 = down;
    int x,y;
    
    // find the borders
    for (int i=0; i<total; i++) {
        x = space[i]->x; y = space[i]->y;
        x1 = x < x1 ? x : x1;
        x2 = x > x2 ? x : x2;
        y1 = y < y1 ? y : y1;
        y2 = y > y2 ? y : y2;   
    }
    
    // calculate the area
    int tmp_area = (y2 - y1) * (x2 - x1);

    // compare the result and update
    if (total > number) {
        number = total;
        area = tmp_area;
    } else if (total == number && area > tmp_area) {
        area = tmp_area;
    }
}
 
int main() {
    int n;
    scanf("%d", &n);
    
    // input data
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
    
    // find the rect and calcute the result
    find(hpt, hnum, 0, 1000, 0, 1000, 0);
    printf("%d %d\n", number, area);
    return 0;
}