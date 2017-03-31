#include <cstdio>
using namespace std;

// struct TreeNode {
// 	int val;
// 	TreeNode *lc;
// 	TreeNode *rc;
// 	TreeNode(int x) : val(x), lc(NULL), rc(NULL) {}
// };

int lc[100000], rc[100000];
int father[100000], children[100000];
int red[100000], number[100000];

int n, p, q;
int t, x;
int w;
/*
 *int st[100000];
 *int top=0;
 *void push(int x) { st[top++] = x; }
 *int pop() { return st[--top]; }
 */

// inOrder traverse tree
// void inOrder(int x) {
// 	if (x == 0) return;
// 	if (lc[x]) inOrder(lc[x]);
// 	push(x);
// 	if (rc[x]) inOrder(rc[x]);
// }

// count children numbers
int countChild(int root) {
	children[lc[root]] = lc[root] ? countChild(lc[root]) : 0;
	children[rc[root]] = rc[root] ? countChild(rc[root]) : 0;
	return children[lc[root]] + children[rc[root]] + 1;
}

// paint color
void paint(int t, int x) {
	// top = 0;
	// inOrder(t);
	x %= children[t];
	while (x != children[lc[t]]) {
		if (x < children[lc[t]]) {
			t = lc[t];
		} else {
			x -= (children[lc[t]] + 1);
			t = rc[t];
		}
	}
	red[t] = 1;
}

// count bulbs
int count(int w) {
	// top = 0;
	// inOrder(w);
	if (lc[w]) number[lc[w]] = count(lc[w]);
	if (rc[w]) number[rc[w]] = count(rc[w]);
	return red[w] + number[lc[w]] + number[rc[w]];
}

int main() {
	scanf("%d%d%d", &n, &p, &q);
	for (int i=0; i<n; i++) {
		int x, l, r;
		scanf("%d%d%d", &x, &l, &r); 
		red[x] = 0; lc[x] = l; rc[x] = r;
		father[l] = father[r] = x;
	}

	int root=0;
	for (int i=1; i <= n; ++i) if (father[i] == 0) { root = i; break; }
	children[root] = countChild(root);
	for (int i=0; i<p; i++) {
		scanf("%d%d", &t, &x);
		paint(t, x);
	}
	number[0] = 0;
	number[root] = count(root);
	for (int i=0; i<q; ++i) {
		scanf("%d", &w);
		printf("%d\n", number[w]);
	}
	return 0;
}
