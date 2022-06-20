#include <iostream>
#include<map>
using namespace std;

int main()
{
    map<int,string> m;

    m[5] = "Premkumar";
    m[1] = "Shriram";
    m[7] = "Rocky";
    m[3] = "Manimala";
    
    for(auto i:m)
    {
        cout<<i.first<<" "<<i.second<<endl;
    }

cout<<endl;
    m.erase(7);
    for(auto i:m)
    {
        cout<<i.first<<" "<<i.second<<endl;
    }

}