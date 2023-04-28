class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        
        if(head==NULL  ||  head->next==NULL  ||  k==0 ) return head;
        
        ListNode* tail = head;
        int len = 1;
        while(tail->next != NULL){
            tail = tail->next;
            len++;
        }
        tail->next = head;    //creating cycle in liked list
        
        k = k % len;         // very important bcz length of node could be less than k
        
        ListNode* temp = head;
        for(int i=1; i<len-k; i++){
            temp = temp->next;
        }
        head = temp->next;          //new head of the node 
        temp->next  = NULL;         //breaking connection with old node
        
        return head;
    }
};
