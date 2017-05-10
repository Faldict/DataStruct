#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

class pos {
public:
    int cats;
    int dogs;
    int mice;
    pos(int c=0,int d=0,int m=0):cats(c),dogs(d),mice(m) {}

    void reset() {
        cats = 0;
        dogs = 0;
        mice = 0;
    }
    friend pos operator+(const pos &a, const pos &b)
    {
        pos tmp;
        tmp.cats = a.cats + b.cats;
        tmp.dogs = a.dogs + b.dogs;
        tmp.mice = a.mice + b.mice;
        return tmp;
    }
    friend pos operator-(const pos &a, const pos &b)
    {
        pos tmp;
        tmp.cats = a.cats - b.cats;
        tmp.dogs = a.dogs - b.dogs;
        tmp.mice = a.mice - b.mice;
        return tmp;
    }

    pos &operator +=(const pos &a)
    {
        cats += a.cats;
        dogs += a.dogs;
        mice += a.mice;
        return *this;
    }
    pos &operator -=(const pos &a)
    {
        cats -= a.cats;
        dogs -= a.dogs;
        mice -= a.mice;
        return *this;
    }
};

char **yard;
int n,m,hx, hy;

pos EN, WN, ES, WS;
pos hup, hdown, hleft, hright;

void calcDgn();

bool legal(int x, int y);

int main()
{
    //init();
    scanf("%d%d",&n,&m);
    yard = new char*[n];
    for (int i=0;i<n;++i)
        yard[i] = new char[m];

    getchar();
    for (int i=0;i<n;++i){
        for (int j=0;j<m;++j){
            scanf("%c",&yard[i][j]);
            if (yard[i][j]=='H'){
                hx = i;hy = j;
            }
        }
        getchar();
    }

    calcDgn();

    for (int i=0;i<n;++i){
        for (int j=0;j<m;++j){
            if (abs(i-hx) < abs(j-hy)){
                if (j < hy){
                    switch (yard[i][j]){
                        case 'C': ++hleft.cats;break;
                        case 'D': ++hleft.dogs;break;
                        case 'M': ++hleft.mice;
                    }
                }
                else{
                    switch (yard[i][j]){
                        case 'C': ++hright.cats;break;
                        case 'D': ++hright.dogs;break;
                        case 'M': ++hright.mice;
                    }
                }
            }
            else if (abs(i-hx) > abs(j-hy)){
                if (i < hx){
                    switch (yard[i][j]){
                        case 'C': ++hup.cats;break;
                        case 'D': ++hup.dogs;break;
                        case 'M': ++hup.mice;
                    }
                }
                else{
                    switch (yard[i][j]){
                        case 'C': ++hdown.cats;break;
                        case 'D': ++hdown.dogs;break;
                        case 'M': ++hdown.mice;
                    }
                }
            }
            else if (i==hx && j==hy){
                switch (yard[i][j]){
                    case 'C': ++hup.cats;++hdown.cats;++hleft.cats;++hright.cats;break;
                    case 'D': ++hup.dogs;++hdown.dogs;++hleft.dogs;++hright.dogs;break;
                    case 'M': ++hup.mice;++hdown.mice;++hleft.mice;++hright.mice;break;
                }
            }
        }
    }

    hup+=EN+WN;
    hdown+=ES+WS;
    hleft+=WN+WS;
    hright+=EN+ES;

    int N;
    scanf("%d",&N);
    getchar();
    char step;

    for (int i=0;i<N;++i){
        scanf("%c",&step);
        if (i<N-1) getchar();
        pos tmpEN = EN, tmpWN = WN, tmpES = ES, tmpWS = WS;

        switch (step){
        case 'N':{
                if (!legal(hx-1,hy)) break;
                hx -= 1;
                calcDgn();
                hup -= tmpEN + tmpWN;
                hdown += WS + ES;
                hleft = hleft + WN - tmpWS;
                hright = hright + EN - tmpES;

                switch (yard[hx+1][hy]){
                    case 'C': --hup.cats;--hleft.cats;--hright.cats;break;
                    case 'D': --hup.dogs;--hleft.dogs;--hright.dogs;break;
                    case 'M': --hup.mice;--hleft.mice;--hright.mice;
                }
                switch (yard[hx][hy]){
                    case 'C': ++hdown.cats;++hleft.cats;++hright.cats;break;
                    case 'D': ++hdown.dogs;++hleft.dogs;++hright.dogs;break;
                    case 'M': ++hdown.mice;++hleft.mice;++hright.mice;
                }

                printf("%d %d %d\n",hup.cats, hup.dogs, hup.mice);
                break;
            }
        case 'S':{
                if (!legal(hx+1,hy)) break;
                hx += 1;

                calcDgn();
                hup += EN + WN;
                hdown -= tmpWS + tmpES;
                hleft = hleft + WS - tmpWN;
                hright = hright + ES - tmpEN;
                switch (yard[hx-1][hy]){
                    case 'C': --hdown.cats;--hleft.cats;--hright.cats;break;
                    case 'D': --hdown.dogs;--hleft.dogs;--hright.dogs;break;
                    case 'M': --hdown.mice;--hleft.mice;--hright.mice;
                }
                switch (yard[hx][hy]){
                    case 'C': ++hup.cats;++hleft.cats;++hright.cats;break;
                    case 'D': ++hup.dogs;++hleft.dogs;++hright.dogs;break;
                    case 'M': ++hup.mice;++hleft.mice;++hright.mice;
                }
                printf("%d %d %d\n",hdown.cats, hdown.dogs, hdown.mice);
                break;
            }
        case 'W':{
                if (!legal(hx,hy-1)) break;
                hy -= 1;

                calcDgn();
                hleft -= tmpWN + tmpWS;
                hright += EN + ES;
                hup = hup + WN - tmpEN;
                hdown = hdown + WS - tmpES;
                switch (yard[hx][hy+1]){
                    case 'C': --hleft.cats;--hup.cats;--hdown.cats;break;
                    case 'D': --hleft.dogs;--hup.dogs;--hdown.dogs;break;
                    case 'M': --hleft.mice;--hup.mice;--hdown.mice;
                }
                switch (yard[hx][hy]){
                    case 'C': ++hright.cats;++hup.cats;++hdown.cats;break;
                    case 'D': ++hright.dogs;++hup.dogs;++hdown.dogs;break;
                    case 'M': ++hright.mice;++hup.mice;++hdown.mice;
                }
                printf("%d %d %d\n",hleft.cats, hleft.dogs, hleft.mice);
                break;
            }
        default:{
                if (!legal(hx,hy+1)) break;
                hy += 1;

                calcDgn();
                hright -= tmpEN + tmpES;
                hleft += WN + WS;
                hup = hup + EN - tmpWN;
                hdown = hdown + ES - tmpWS;
                switch (yard[hx][hy-1]) {
                    case 'C': --hright.cats;--hup.cats;--hdown.cats;break;
                    case 'D': --hright.dogs;--hup.dogs;--hdown.dogs;break;
                    case 'M': --hright.mice;--hup.mice;--hdown.mice;
                }
                switch (yard[hx][hy]){
                    case 'C': ++hleft.cats;++hup.cats;++hdown.cats;break;
                    case 'D': ++hleft.dogs;++hup.dogs;++hdown.dogs;break;
                    case 'M': ++hleft.mice;++hup.mice;++hdown.mice;
                }
                printf("%d %d %d\n",hright.cats, hright.dogs, hright.mice);
                break;
            }
        }
    }
}

void calcDgn()
{
    int x, y;

    EN.reset();WN.reset();WS.reset();ES.reset();

    x = hx - 1; y = hy + 1;
    while (legal(x,y)){
        switch (yard[x][y]){
            case 'C': ++EN.cats;break;
            case 'D': ++EN.dogs;break;
            case 'M': ++EN.mice;
        }
        --x;++y;
    }

    x = hx - 1; y = hy - 1;
    while (legal(x,y)){
        switch (yard[x][y]){
            case 'C': ++WN.cats;break;
            case 'D': ++WN.dogs;break;
            case 'M': ++WN.mice;
        }
        --x;--y;
    }

    x = hx + 1; y = hy - 1;
    while (legal(x,y)){
        switch (yard[x][y]){
            case 'C': ++WS.cats;break;
            case 'D': ++WS.dogs;break;
            case 'M': ++WS.mice;
        }
        ++x;--y;
    }

    x = hx + 1; y = hy + 1;
    while (legal(x,y)){
        switch (yard[x][y]){
            case 'C': ++ES.cats;break;
            case 'D': ++ES.dogs;break;
            case 'M': ++ES.mice;
        }
        ++x;++y;
    }
}

bool legal(int x, int y)
{
    return (x>=0 && x<n && y>=0 && y<m);
}
