#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

int lines=1;
char text[200][2000];

int len(char *line) {
    int count = 0;
    while(line[count] != '\0') count++;
    return count;
}

void list(int a, int b) {
    if (a>lines || b>lines || a<=0 || a>b) cout<<"Error!"<<endl;
    else for (int i=a; i<=b; i++) cout<<text[i]<<endl;
}

void ins(int i,int j, char * c)
{    
     if (j<=0||i<=0||i>lines||(j>1+len(text[i])))cout<<"Error!"<<endl;
     else
     {
        int tmp=len(text[i]);
        for (int k=tmp-1;k>=j-1;k--)
        {
            int e=k+len(c);
            text[i][e]=text[i][k];
        }
        for (int k=j-1,q=0;q<=len(c)-1;q++,k++)
        {
            text[i][k]=c[q];
        }
        text[i][tmp+len(c)]='\0';
     }
}

void del(int i,int j, int n)
{
    if (i<=0||j<=0||n<0||i>lines||j>len(text[i])||((j+n)>len(text[i])+1)) cout<<"Error!"<<endl;
    else
    {
        int tmp=len(text[i]);
        for (int k=j+n-1;k<=tmp-1;k++)
        {
            text[i][k-n]=text[i][k];
        }
        text[i][tmp-n]='\0';
    }
}


int main() {
    // read the file
    while (true) {
        cin.getline(text[lines], 2000);
        if (strcmp(text[lines],"******") == 0) break;
        lines++;
    }
    lines--;

    while (true) {
        char command[10];
        cin>>command;
        if (strcmp(command, "quit") == 0) break;
        else if (strcmp(command, "list") == 0) {
            int a, b;
            cin>>a>>b;
            list(a,b);
        }
        else if (strcmp(command, "ins") == 0) {
            int a, b;
            char s[100];
            cin>>a>>b;
            cin.get(s, 100);
            ins(a, b, s);
        }
        else if (strcmp(command, "del") == 0) {
            int a, b, n;
            cin>>a>>b>>n;
            del(a, b, n);
        }
    }

    for (int i=1; i<=lines; i++) cout<<text[i]<<endl;
    return 0;
}