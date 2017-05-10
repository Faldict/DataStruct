#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
 
struct Node {
	int father;
	vector<int> child;
	Node() : father(0), child() {};
} tree[40010];
int d[40010];
 
void build(int root, int deep) {
	for (int i = 0; i < tree[root].child.size(); i++) {
		if (tree[root].child[i] != tree[root].father) {
			int c = tree[root].child[i];
			tree[c].father = root;
			d[c] = deep;
			build(c, deep + 1);
		}
		else {
			tree[root].child.erase(tree[root].child.begin() + i);
			i--;
		}
	}
}
 
bool isAccester(int x, int y) {
	if (y == -1) return false;
	if (x == y) return true;
	if (d[y] - d[x] > 20) return true;
	return isAccester(x, tree[y].father);
}
 
int main() {
	int n, m; int root;
	scanf("%d", &n);
	for (int i=0; i<n; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		if (a == -1) {
			root = b;
			tree[b].father = -1;
			continue;
		}
		else if (b == -1) {
			root = a;
			tree[a].father = -1;
			continue;
		}
		tree[a].child.push_back(b);
		tree[b].child.push_back(a);
	}
 
	build(root, 1);
	scanf("%d", &m);
	for (int i=0; i<m; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		if (d[x] < d[y]) {
			if (isAccester(x, y)) printf("1\n");
			else printf("0\n");
		}
		else if (d[x] > d[y]) {
			if (isAccester(y, x)) printf("2\n");
			else printf("0\n");
		}
		else {
			printf("0\n");
		}
	}
	return 0;
}