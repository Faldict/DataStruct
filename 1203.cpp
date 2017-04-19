#include <iostream>
#include <string.h>
using namespace std;

template<typename T>
class Link {
private:
    T *data;
    int size;

public:
    Link(int n = 0);//create a list of size n
    Link(const Link &l);//copy an new list from existing list
    ~Link() { delete[] data; }
    friend istream& operator>>(istream &is, Link<T> &l) {};
    friend ostream& operator<<(ostream &os, Link<T> &l) {};
    friend Link<T> operator+(Link<T> &l1, Link<T> &l2) {};
};

template<typename T>
Link<T>::Link(int n)
{
    data = new T [n];
    size = n;
}

template<typename T>
Link<T>::Link(const Link<T> &l)
{
    data = new T[l.size];
    size = l.size;
    for (int i = 0; i < l.size; i++)
        data[i] = l.data[i];
}

template<typename T>
istream& operator>>(istream &is, Link<T> &l){
    for (int i = 0; i < l.size; i++) {
        is >> l.data[i];
    }
    return is;
}

template<typename T>
ostream& operator<<(ostream &os, Link<T> &l)//use for output
{
    for (int i = 0; i < l.size; i++)
        os << l.data[i] << " ";
    return os;
}

template<typename T>
Link<T> operator+(Link<T> &l1, Link<T> &l2)//use for add
{
    Link<T> l(l1.size + l2.size);
    for (int i = 0; i < l1.size; i++)//copy l1 to l
        l.data[i] = l1.data[i];
    for (int i = 0; i < l2.size; i++)//copy l2 to l
        l.data[i + l1.size] = l2.data[i];
    return l;
}

int main()
{
    char type[100];
    int n1, n2;
    cin >> type;
    cin >> n1 >> n2;
    if (strcmp(type, "int") == 0)
    {
        Link<int> l1(n1), l2(n2), l;
        cin >> l1;
        cin >> l2;
        l = l1 + l2;
        cout << l << endl;
    }
    else if (strcmp(type, "char") == 0)
    {
        Link<char> l1(n1), l2(n2), l(n1 + n2);
        cin >> l1;
        cin >> l2;
        l = l1 + l2;
        cout << l << endl;
    }
    else
    {
        Link<double> l1(n1), l2(n2), l(n1 + n2);
        cin >> l1;
        cin >> l2;
        l = l1 + l2;
        cout << l << endl;        
    }
    return 0;
}