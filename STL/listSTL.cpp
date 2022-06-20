#include<iostream>
#include<list>
using namespace std;

int main()
{
    list<int> l;
    l.push_back(1);
    l.push_back(2);
    l.push_front(0);

    for(int i:l)
    {
        cout<<i<<" ";
    }
    cout<<endl;

    list<int> a(5,100);
    for(int i:a)
    {
        cout<<i<<" ";
    }
}