#include <cstdio>
#include <queue>
using namespace std;

struct tree {
    int val;
    tree *left,*right;
};

void insert(tree*& t, int val) {
    if (t==NULL)
    {
        t=new tree;
        t->left=NULL;
        t->right=NULL;
        t->val=val;
    } else if (t->val == val) return;
    else if (t->val > val) insert(t->left,val);
    else insert(t->right,val);
}

void find(tree* h, int val) {
    queue<char> res;
    res.push('*');
    while (h!=NULL)
    {
        if (h->val == val) break;
        else if (h->val < val)
        {
            h=h->right;
            res.push('r');
        } else
        {
            h=h->left;
            res.push('l');
        }
    }
    if (h==NULL) printf("Nothing.\n");
    else
    {
        while (!res.empty())
        {
            printf("%c",res.front());
            res.pop();
        }
        printf("\n");
    }
}

void remove(tree*& t, int val) {
    if (t==NULL) return;
    else if (t->val == val)
    {
        tree *tmp;
        if (t->right == NULL)
        {
            tmp=t;
            t=t->left;
            delete tmp;
        } else if (t->right->left == NULL)
        {
            tmp=t->right;
            t->val=t->right->val;
            t->right=t->right->right;
            delete tmp;
        } else
        {
            for (tmp=t->right;tmp->left->left != NULL;tmp=tmp->left);
            t->val=tmp->left->val;
            tree *tt=tmp->left;
            tmp->left=tmp->left->right;
            delete tt;
        }
    } else if (t->val > val) remove(t->left,val);
    else remove(t->right,val);
}

int main() {
    // freopen("1560.in","r",stdin);
    int n,i,t;
    char f;
    scanf("%d",&n);
    tree *head=NULL;
    for (i=0;i<n;++i)
    {
        getchar();
        scanf("%c %d",&f,&t);
        if (f=='+') insert(head,t);
        else if (f=='-') remove(head,t);
        else find(head,t);
    }
}