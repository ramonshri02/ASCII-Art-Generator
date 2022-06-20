#include<iostream>
#include<queue>
using namespace std;

int main()
{
    // PRIORITY QUEUE
    priority_queue<int> p;  //  by default it gives values in descending order

    p.push(15);
    p.push(24);
    p.push(7);
    p.push(13);
    p.push(9);

    int n = p.size();

    for(int i=0; i<n; i++)
    {
        cout<<p.top()<<" ";
        p.pop();
    }
    cout<<endl;

    priority_queue<int, vector<int>,greater<int> > mini;  // gives ascending order
    mini.push(15);
    mini.push(24);
    mini.push(7);
    mini.push(13);
    mini.push(9);

    int m = mini.size();
    for(int i=0; i<m; i++)
    {
        cout<<mini.top()<<" ";
        mini.pop();
    }

}