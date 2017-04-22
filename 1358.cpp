#include <iostream>

using namespace std;

struct Node {
	int val;
	int size;
	Node* next;
	Node(int _val = 0, Node* _next = NULL) : val(_val), next(_next), size(0) {};
};

int n;

Node tree[10000];
int degree[10000];

int getSon(int node, int father) {
	Node *p = tree[node].next;
	int size = 0;
	Node *fp = NULL;
	while (p) {
		if (p->val == father) fp = p;
		else {
			p->size = getSon(p->val, node);
			size += p->size;
		}
		p = p->next;
	}
	if (fp) fp->size = n - size - 1;
	return size + 1;
}

int main() {
	cin>>n;

	for (int i=1; i<n; i++) {
		int x, y;
		cin>>x>>y;

		tree[x].next = new Node(y, tree[x].next);
		tree[y].next = new Node(x, tree[y].next);
		degree[x]++; degree[y]++;
	}

	getSon(1, 0);
	for (int i=1; i<=n; i++) {
		Node *p = tree[i].next;
		bool flag = true;
		while(p) {
			flag = p->size > n / 2 ? false : flag;
			p = p->next;
		}
		if (flag) cout<<i<<endl;
	}
	return 0;
}