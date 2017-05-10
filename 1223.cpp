#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
 
struct tank {
  int id;
  int power;
  int mark;
  tank() : id(0), power(0), mark(0) {};
} fish[200010];
 
bool cmp(const tank &lt, const tank &rt) {
  if (lt.mark == rt.mark) return lt.id < rt.id;
  return lt.mark > rt.mark;
}
 
int main() {
  int n, r, tmp;
 
  scanf("%d %d", &n, &r);
  for (int i = 1; i <= 2 * n; i++) {
    scanf("%d", &tmp);
    fish[i].id = i;
    fish[i].mark = tmp;
  }
  for (int i = 1; i <= 2 * n; i++) {
    scanf("%d", &tmp);
    fish[i].power = tmp;
  }
  
  sort(fish + 1, fish + 2 * n + 1, cmp);
  for (int i=0; i < r; i++) {
    for (int j = 1; j <= n; j++) {
      int a = 2 * j - 1, b = 2 * j;
      int c;
      if (fish[a].power < fish[b].power) {
        fish[b].mark++;
        c = b;
      }
      else {
        fish[a].mark++;
        c = a;
      }
      while(c > 1 && (fish[c].mark > fish[c-1].mark || fish[c].mark == fish[c-1].mark && fish[c].id < fish[c-1].id)) {
      	swap(fish[c], fish[c-1]);
      	c--;
      }
    }
  }
  for (int i = 1; i <= 2 * n; i++) 
    printf("%d ", fish[i].id);
  return 0;
}