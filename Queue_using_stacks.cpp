//Queue using 2 stacks
// *deque method is not working (don't know why)


#include <iostream>
#include <stack>

using namespace std;

stack<int> newestStack;
stack<int> oldestStack;

void move(){
    while(!newestStack.empty()){
        int k = newestStack.top();
        oldestStack.push(k);
        newestStack.pop();
    }
}

void enque(int x){
    for(int i=0; i<x; i++){
        int p;
        cin>>p;
        newestStack.push(p);
    }
}

void deque(int d){
    move();
    for(int i=0; i<d; i++){
        oldestStack.pop();
    }
    
}

int main()
{
    cout<<"How many elements u want to ADD to queue ";
    int a;
    cin>>a;
    cout<<"Enter Elements "<<endl;
    for(int i=0; i<a; i++){
        int p;
        cin>>p;
        newestStack.push(p);
    }
    cout<<endl;
    cout<<"Enter 1 to add element or 2 to delete element from Queue ";
    int n;
    cin>>n;
    
    if(n==1){
        cout<<"How many elements u want to ADD to queue ";
        int x;
        cin>>x;
        enque(x);
    }
    else if(n==2){
        cout<<"How many Elements you want to DELETE ";
        int d;
        cin>>d;
        move();
        for(int i=0; i<d; i++){
            oldestStack.pop();
        }
    }
    cout<<" Now the queue is "<<endl;
    move();
    while( !oldestStack.empty() ){
        cout<<oldestStack.top();
        oldestStack.pop();
    }

    return 0;
}
