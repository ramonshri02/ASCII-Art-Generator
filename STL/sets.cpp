#include<iostream>
#include<set>
using namespace std;

int main()
{
    set<int> s;

    s.insert(5);
    s.insert(5);
    s.insert(5);
    s.insert(5);
    s.insert(1);
    s.insert(8);
    s.insert(8);
    s.insert(0);

    for(auto i:s)
    {
        cout<<i<<" ";
    }
    cout<<endl;
    s.erase(s.begin());
    for(auto i:s)
    {
        cout<<i<<" ";
    }
    cout<<endl;

    cout<<"Is 5 present or not? "<<s.count(5);
    cout<<endl;
    cout<<"Is -32 present or not? "<<s.count(-32);
}