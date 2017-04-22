#include <cstdio>
#include <vector>
 
using namespace std;
 
struct Node {
    vector<int> child;
    int num;
    Node() : child(), num(0) {};
};
 
Node Tree[100000];
int r;
 
void build(int node, int father) {
    if (node != r && Tree[node].child.size() <= 1) {
        Tree[node].num = -1;
    } else {
        for (int i=0; i < Tree[node].child.size(); i++) if (Tree[node].child[i] != father) {
            int c = Tree[node].child[i];
            build(c, node);
            // Tree[node].num = max(Tree[c].num, Tree[node].num);
            Tree[node].num = max(c, Tree[node].num);
        }
    }
}
 
int main() {
    int n;
    scanf(" %d%d", &n, &r);
 
    int x, y;
    for (int i=1; i<n; i++) {
        scanf(" %d%d", &x, &y);
        Tree[y].child.push_back(x);
        Tree[x].child.push_back(y);
    }
 
    build(r, -1);
    
    int q, k;
    scanf(" %d", &q);
    for (int i=0; i<q; i++) {
        scanf(" %d", &k);
        printf("%d\n", Tree[k].num);
    }
 
    return 0;
}