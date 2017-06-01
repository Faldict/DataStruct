#include <iostream>
#include <cstdio>
#include <stack>
using namespace std;

int N,X,Y;

struct node {
    node *left;
    node *right;
    int num;
    node() {}
    node (int a, node *l=NULL,node *r=NULL):num(a),left(l),right(r) {}
};

class tree {
public:
    node *root;
    tree(){root=NULL;}
    tree(node *t){root=t;}
    int result() {
        if (root->num==0) return 0;
        int res=0;
        lca(root,res,NULL);
        return res;
    }  

    bool lca(node *root,int &res,node*parent) {
        bool left=false;
        bool  right=false;
        if (!res &&root->left->num!=0) left=lca(root->left,res,root);
        if (!res &&root->right->num!=0) right=lca(root->right,res,root);
        bool mid=false;
        if (root->num == X || root->num == Y) mid=true;
        if (!res && int(left + right + mid) == 2) {
            if (mid) res= parent->num;
            else res = root->num;
        }
        return left | mid | right ;
    }
};

int main() {
    cin>>N>>X>>Y;
    tree *all;
    all=new tree [N+1];
    bool *flag;
    flag=new bool[N+1];
    for (int i=0;i<=N;i++) {
        all[i].root=new node(i);
        flag[i]=false;
    }
    for(int i=1;i<=N;i++) {
        int a, b;
        cin>>a>>b;
        all[i].root->left=all[a].root;
        all[i].root->right=all[b].root;
        flag[a]=flag[b]=true;
    }
    int root;
    for (int i=1;i<N+1;i++) {
        if (!flag[i]) {
          root=i;
          break;
        }
    }
    cout<<all[root].result()<<endl;
    return 0;
}