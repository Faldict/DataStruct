#include <iostream>
#include <cstring>

using namespace std;

char preorder[30];
char inorder[30];

char stack[1010];

int last = 0;

void build(int index, int pre, int in, int n) {
    if (n <= 0) return;
    if (index > last) last = index;
    // cout<<index<<" "<<pre<<" "<<in<<" "<<n<<endl;
    stack[index] = preorder[pre];
    if (n > 1) {
        for (int i=0; i < n; i++) {
            if (inorder[i + in] == preorder[pre]) {
                build(index << 1, pre + 1, in, i);
                build((index << 1) + 1, pre + i + 1, in + i + 1, n - i - 1);
                break;
            }
        }
    }
}

int main() {
    cin>>preorder;
    cin>>inorder;

    build(1, 0, 0, strlen(preorder));
    for (int i=1; i <= last; i++) {
        if (stack[i] >= 'A') cout<<stack[i]<<" ";
        else cout<<"NULL ";
    }

    return 0;
} 