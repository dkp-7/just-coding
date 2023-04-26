#include <iostream>
using namespace std;

class node{
    public:
    int val;
    node* next;
    
    node(int n){
        val = n;
        next = NULL;
    }
    
};


void insert(node* &head , int n){
    
    node* newNode = new node(n);
    
    if(head == NULL){
        head = newNode;
        return;
    }
    node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newNode;
}


void deleteNode1(node* head , int k){
    
    while(head->next->val != k){
        head = head->next;
    }
    head->next = head->next->next;
}

void deleteNode2(node* d){
    d->val = d->next->val;
    d->next = d->next->next;
}

node* getNode(node* head , int k){
    while(head->val != k){
        head = head->next;
    }
    return head;
}

void printLList(node* head){
    while(head != NULL){
        cout<<head->val<<" --> ";
        head = head->next;
    }
}


int main()
{
    node*head = NULL;
    //node* head = new node(4);   (when using this & not above line, we can remove '&' from insert function)
    
    insert(head , 1);
    insert(head , 2);
    insert(head , 3);
    insert(head , 4);
    insert(head , 5);
    insert(head , 6);
    insert(head , 7);
    insert(head , 8);
    
    cout<<"New lINKED LIST"<<endl;
    printLList(head);
    cout<<endl<<endl;
    
    cout<<"Deleting element '3'"<<endl;
    deleteNode1(head , 3);
    printLList(head);
    cout<<endl<<endl;
    
    cout<<"Deleting node that contains element '6'"<<endl;
    node* d = getNode(head , 6);
    deleteNode2(d);
    printLList(head);
    
    return 0;
}
