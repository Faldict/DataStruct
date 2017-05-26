#include <iostream>
#include <cstdio>
#include <vector>
#include <stack>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        TreeNode *root=NULL; stack<TreeNode *> MyData;
        if(preorder.empty()) return root;
        root = new TreeNode(preorder[0]);
        MyData.push(root); int index = 0;
       	for(int i=1; i<=preorder.size(); i++) {
       		TreeNode *cur = MyData.top();
       		if((MyData.top()->val)!=inorder[index]) {
       			cur->left = new TreeNode(preorder[i]);
       			MyData.push(cur->left);
       		} else {
       			while(!MyData.empty() && ((MyData.top()->val)==inorder[index])) {
       				cur=MyData.top(); MyData.pop(); index++; 
       			}
       			if(index<inorder.size()) {
       				cur->right = new TreeNode(preorder[i]);
       				MyData.push(cur->right);
       			} 
       		}  
       	}
       	return root;
}

void postOutput(TreeNode *root) {
	if (root->left) postOutput(root->left);
	if (root->right) postOutput(root->right);
	printf("%d ", root->val);
}

int main() {
	int n;
	scanf("%d", &n);
	vector<int> preorder(n), inorder(n);
	for (int i=0; i<n; i++) scanf("%d", &preorder[i]);
	for (int i=0; i<n; i++) scanf("%d", &inorder[i]);

	TreeNode* root = buildTree(preorder, inorder);
	postOutput(root);
	printf("\n");
	return 0;
}