// Question : Flattening a linked list (GFG : https://practice.geeksforgeeks.org/problems/flattening-a-linked-list/1 )


Node* merge(Node* a, Node* b){
    
    Node* temp = new Node(0);
    Node* temp1 = temp;
    while(a != NULL  &&  b != NULL){
        
        if(a->data < b->data){
            temp->bottom = a;
            temp = temp->bottom;
            a = a->bottom;
        }
        else{
            temp->bottom = b;
            temp = temp->bottom;
            b = b->bottom;
        }
        
        if(a) temp->bottom = a;
        else temp->bottom = b;
    }
    return temp1->bottom;
}
    
    
Node *flatten(Node *root)
{
   if(root->next == NULL){
       return root;
   }
   
   Node* b = flatten(root->next);
   
   Node* ans = merge(root , b);
   
   return ans;
}



//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// this below code didn't worked   (In this I was creating a new linked list to store the flattened linked list)

Node *flatten(Node *root)
{
   // Your code here
   Node* l1 = root;
   Node* l2 = root->next;
   
   
   Node* ans = new Node(0);
   Node* ansHead = ans->bottom;
   
   while(l2 != NULL){
       Node* l2_next = l2->next;
       while(l1 != NULL  &&  l2 != NULL){
           
           Node* temp = new Node(0);
           //Node* temp1 = temp->bottom;
           
           if(l1->data <= l2->data){
               temp->data = l1->data;
               l1 = l1->bottom;
           }
           else{
               temp->data = l2->data;
               l2 = l2->bottom;
           }
           
           ans->bottom = temp;
           ans = temp;
       }
       
       while(l1 != NULL){
           Node* temp = new Node(0);
           //Node* temp1 = temp->bottom;
           temp->data = l1->data;
           ans->bottom = temp;
           ans = temp;
           l1 = l1->bottom;
           //l2 = l2->bottom;
       }
       
       while(l1 != NULL){
           Node* temp = new Node(0);
           //Node* temp1 = temp->bottom;
           temp->data = l2->data;
           ans->bottom = temp;
           ans = temp;
           //l1 = l1->bottom;
           l2 = l2->bottom;
       }
       
       l1 = ansHead;
       l2 = l2_next;
   }
   return ansHead;
}
