#include <iostream>
#include <array>
#include <vector>
#include<deque>
using namespace std;

int main()
{
    // ARRAYS
    array<int,4> a = {1,2,3,4};
    for (int i=0; i<4; i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
    cout<<"Element at 3rd index: "<<a.at(3)<<endl;  
    cout<<"Empty or not ? "<<a.empty()<<endl;
    cout<<"First element: "<<a.front()<<endl;
    cout<<"Last element: "<<a.back()<<endl<<endl;

    // VECTORS

    vector<int> v;
    
    cout<<"Size: "<<v.size()<<endl;   //gives how much elements are stored at present
    cout<<"Capacity: "<<v.capacity()<<endl;  //gives how much more elements CAN BE stored

    v.push_back(1);
    cout<<"Size: "<<v.size()<<endl;
    cout<<"Capacity: "<<v.capacity()<<endl;

    v.push_back(2);
    cout<<"Size: "<<v.size()<<endl;
    cout<<"Capacity: "<<v.capacity()<<endl;

    v.push_back(3);
    cout<<"Size: "<<v.size()<<endl;
    cout<<"Capacity: "<<v.capacity()<<endl;

    v.push_back(4);
    cout<<"Size: "<<v.size()<<endl;
    cout<<"Capacity: "<<v.capacity()<<endl;

    v.push_back(5);
    cout<<"Size: "<<v.size()<<endl;
    cout<<"Capacity: "<<v.capacity()<<endl;

    cout<<"Element at 3rd index: "<<v.at(0)<<endl;

    cout<<"First element: "<<v.front()<<endl;
    cout<<"Last element: "<<v.back()<<endl;

    // Traversing the vector
    cout<<"Traversing the vector: ";
    for(int i:v)
    {
        cout<<i<<" ";
    }
    cout<<endl;

    v.pop_back();

    cout<<"Traversing the vector after POP BACK: ";
    for(int i:v)
    {
        cout<<i<<" ";
    }

    v.clear();
    cout<<endl;

    cout<<"Traversing the vector after CLEARING: ";
    for(int i:v)
    {
        cout<<i<<" ";
    }

    cout<<endl;

    cout<<"Size of array after CLEARING: "<<v.size()<<endl<<endl;

    // DEQUE

    deque<int> d;
    d.push_back(1);
    d.push_back(2);
    d.push_back(3);
    d.push_back(4);
    d.push_back(5);

    for(int i:d)
    {
        cout<<i<<" ";
    }
    cout<<endl;
    d.push_front(0);
    for(int i:d)
    {
        cout<<i<<" ";
    }

    d.pop_back();
    for(int i:d)
    {
        cout<<i<<" ";
    }

    d.pop_front();
    for(int i:d)
    {
        cout<<i<<" ";
    }
    cout<<endl<<endl;
    for(int i:d)
    {
        cout<<i<<" ";
    }

    cout<<endl;

    cout<<"Checking empty or not: "<<d.empty();
    cout<<endl<<d.at(0);
    cout<<endl;

    d.erase(d.begin(),d.begin()+2);
    for(int i:d)
    {
        cout<<i<<" ";
    }







}