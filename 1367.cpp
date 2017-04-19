#include <iostream>

using namespace std;

struct TreeNode {
	TreeNode *child[2];
	TreeNode() {child[0] = NULL; child[1] = NULL;}
};

int a[30000], b[30000];

TreeNode* buildTree(int n) {
	TreeNode *root = new TreeNode(), *cur;
	for (int i=0; i<n; i++) {
		int num = a[i];
		cur = root;
		for (int j=31; j>=0; j--) {
			int index = (num >> j) & 1;
			if (cur->child[index]) cur = cur->child[index];
			else {
				cur->child[index] = new TreeNode();
				cur = cur->child[index];
			}
		}
	}
	return root;
}

int findMaxXOR(TreeNode *root, int b) {
	int res = 0;
	TreeNode *cur = root;
	for (int j=31; j>=0; j--) {
		int index = ((b >> j) & 1) ? 0 : 1;
		if (cur->child[index]) {
			res <<= 1;
			res |= 1;
			cur = cur->child[index];
		}
		else {
			res <<= 1;
			res |= 0;
			cur = cur->child[index ? 0 : 1];
		}
	}
	return res;
}

int main() {
	int n, m;
	cin>>n>>m;
	for (int i=0; i<n; i++) cin>>a[i];
	TreeNode *root = buildTree(n);
	int res = 0;
	for (int i=0; i<m; i++) {
		cin>>b[i];
		res = max(res, findMaxXOR(root, b[i]));
	}
	cout<<res<<endl;
	return 0;
}