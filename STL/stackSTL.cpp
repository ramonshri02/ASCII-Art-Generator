#include<iostream>
#include<stack>
#include<queue>
using namespace std;

int main()
{
    stack <string> s;

    // LAST IN FIRST OUT CONCEPT
    cout<<endl<<"STACK "<<endl<<endl;
    s.push("Shriram");
    s.push("Manimala");
    s.push("Premkumar");
    cout<<"Size of stack before popping: "<<s.size()<<endl;

    cout<<"Top Element: "<<s.top()<<endl;
    s.pop();
    cout<<"Top Element after popping: "<<s.top()<<endl;
    cout<<"Size of stack after popping: "<<s.size()<<endl;
    cout<<"Empty or not? "<<s.empty()<<endl;

    queue <string> q;

    //FIRST IN FIRST OUT CONCEPT
    cout<<endl<<"QUEUE "<<endl<<endl;
    q.push("Shriram");
    q.push("Manimala");
    q.push("Premkumar");
    cout<<"Size of queue before popping: "<<q.size()<<endl;

    cout<<"Front Element: "<<q.front()<<endl;
    q.pop();
    cout<<"Front Element after popping: "<<q.front()<<endl;
    cout<<"Size of queue after popping: "<<q.size()<<endl;
    cout<<"Empty or not? "<<q.empty()<<endl;

}