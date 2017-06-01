#include<iostream>
#include<cstdio>
#include <stack>
using namespace std;

class DisjointSet{
private:
    int size;
    int *parent;

public:
    DisjointSet(int s) {
        size=s;
        parent=new int [size++];
        for (int i=1;i<=size;++i) parent[i]=-1;
    }
    ~DisjointSet(){delete [] parent;}

    void Union(int root1,int root2) {
        if (root1 == root2) return;
        if (parent[root1] > parent[root2]) {
            parent[root2] += parent[root1];parent[root1]=root2;
        }
        else {
            parent[root1] += parent[root2];parent[root2]=root1;
        }
    }

    int Find(int x) {
        int start=x;
        int tmp;
        while(!(parent[x]<0)) x=parent[x];
        while (start!=x) {
            tmp=parent[start];
            parent[start]=x;
            start=tmp;
        }
        return x;
    }
};

void change(int pos, int &row, int &col) {
    row = 1, col = 1;
    while(pos > row) {
        pos = pos - row;
        row++;
    }
    col = pos;
}

void creatPuzzle(int n, int start, int enda) {
    int sizea = n * (n + 1) / 2;
    int row, col, pos1, pos2, direction;
    int i, j;
    bool **istrue = new bool*[sizea + 1];
    for(i = 0; i <= sizea; i++) {
        istrue[i] = new bool[sizea + 1];
        for(j = 0; j <= sizea; j++)
            istrue[i][j] = false;
    }

    DisjointSet ds(sizea);
    while(ds.Find(start) != ds.Find(enda)) {
        scanf("%d%d", &pos1, &direction);
        change(pos1, row, col);
        switch(direction) {
        case 0: {
                if(col != 1) {
                    pos2 = (row - 1) * (row - 2) / 2 + col - 1;
                    istrue[pos1][pos2] = true;
                    istrue[pos2][pos1] = true;
                    if(ds.Find(pos1) != ds.Find(pos2))
                       ds.Union(ds.Find(pos1), ds.Find(pos2));
                }
                break;
            }
        case 1: {
                if(col != row) {
                    pos2 = (row - 1) * (row - 2) / 2 + col;
                    istrue[pos1][pos2] = true;
                    istrue[pos2][pos1] = true;
                    if(ds.Find(pos1) != ds.Find(pos2))
                        ds.Union(ds.Find(pos1), ds.Find(pos2));
                }
                break;
            }
        case 2: {
                if(row != n) {
                    pos2 = (row + 1) * row / 2 + col;
                    istrue[pos1][pos2] = true;
                    istrue[pos2][pos1] = true;
                    if(ds.Find(pos1) != ds.Find(pos2))
                        ds.Union(ds.Find(pos1), ds.Find(pos2));
                }
                break;
            }
        case 3: {
                if(row != n) {
                    pos2 = (row + 1) * row / 2 + col + 1;
                    istrue[pos1][pos2] = true;
                    istrue[pos2][pos1] = true;
                    if(ds.Find(pos1) != ds.Find(pos2))
                        ds.Union(ds.Find(pos1), ds.Find(pos2));
                }
                break;
            }
        default:
            break;
        }
    }
    bool *vis;
    vis = new bool[sizea + 1];
    for(i = 0; i <= sizea; i++)
        vis[i] = false;
    int tmp, next;
    int rowtmp, coltmp;
    stack<int> stk;
    stack<int> res;
    stk.push(start);
    while(!stk.empty()){
        tmp = stk.top();
        vis[tmp] = true;
        if(tmp == enda)
            break;
        change(tmp, rowtmp, coltmp);
        if(coltmp != 1)
        {
            next = (rowtmp - 1) * (rowtmp - 2) / 2 + coltmp - 1;
            if(istrue[tmp][next] && !vis[next])
            {
                stk.push(next);
                continue;
            }
        }
        if(coltmp != rowtmp)
        {
            next = (rowtmp - 1) * (rowtmp - 2) / 2 + coltmp;
            if(istrue[tmp][next] && !vis[next])
            {
                stk.push(next);
                continue;
            }
        }
        if(rowtmp != n)
        {
            next = rowtmp * (rowtmp + 1) / 2 + coltmp;
            if(istrue[tmp][next] && !vis[next])
            {
                stk.push(next);
                continue;
            }
        }
        if(rowtmp != n)
        {
            next = rowtmp * (rowtmp + 1) / 2 + coltmp + 1;
            if(istrue[tmp][next] && !vis[next])
            {
                stk.push(next);
                continue;
            }
        }
        stk.pop();
    }
    while(!stk.empty()) {
        tmp = stk.top();
        stk.pop();
        res.push(tmp);
    }
    while(!res.empty()) {
        tmp = res.top();
        printf("%d ", tmp);
        res.pop();
    }
}

int main() {
    int n, x, y;
    scanf("%d%d%d", &n, &x, &y);
    creatPuzzle(n, x, y);
}
