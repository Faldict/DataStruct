#include <iostream>
using namespace std;

struct Node{
	Node(int _number) : number(_number), left(NULL), right(NULL){}
	int number;
	Node *left, *right;
};

int total_number, number, left_child, right_child;
pair<int, Node *> nodes[30010] = {};

void addNode(){
	if(left_child > 0){
		nodes[left_child].second = nodes[number].second->left = new Node(left_child);
		nodes[left_child].first = 2 * nodes[number].first;
	}
	if(right_child > 0){
		nodes[right_child].second = nodes[number].second->right = new Node(right_child);
		nodes[right_child].first = 2 * nodes[number].first + 1;
	}
}

void posterOrder(Node *root){
	if(root->left)
		posterOrder(root->left);
	if(root->right)
		posterOrder(root->right);
	cout << root->number << " ";
}

int main(){
	nodes[1].first = 1;
	nodes[1].second = new Node(1);
	cin >> total_number;
	for(int i = 1; i <= total_number; ++i){
		cin >> number >> left_child >> right_child;
		addNode();
	}
	for(int i = 1; i <= total_number; ++i)
		cout << nodes[i].first << " ";
	cout << "\n";
	posterOrder(nodes[1].second);
}