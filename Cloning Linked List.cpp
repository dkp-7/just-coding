// see clone function to understand how cloning is donr in this program


#include <iostream>
using namespace std;
 
class node {
public:
    int val;
    node* next;
    
    node(int x){
        val = x;
        next = NULL;
    }
};

void insert(node* &head, int val){
    node* n1 = new node(val);
    if(head == NULL){
        head = n1;
        return;
    }
    node* head1 = head;
    while(head1->next != NULL){
        head1 = head1->next;
    }
    head1->next = n1;
    return;
}

void printl(node* head){
    node* head1 = head;
    while(head1 != NULL){
        cout<<head1->val<<" --> ";
        head1 = head1->next;
    }
    return;
}

////////////////////////////////////////////////////////////

node* clone(node* nex){
    if(nex == NULL){
        return NULL;
    }
    node* nex2 = clone(nex->next);      //making recursive calls till we reach end of original linked list
    node* new1 = new node(nex->val);
    new1->next = nex2;
    return new1;
}

////////////////////////////////////////////////////////////

int main()
{
    node* head = NULL;
    
    insert(head , 1);
    insert(head , 2);
    insert(head , 3);
    insert(head , 4);
    
    printl(head);
    cout<<endl;
    
   /// cloning above list
   
   node* ans = clone(head);
   
   printl(ans);
   cout<<endl;
   insert(ans, 6);
   printl(ans);
   cout<<endl;
   printl(head);

    return 0;
}
