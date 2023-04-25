// Leetcode:    2. Add Two Numbers of linked list and store it in linked list



/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode* temp = new ListNode();
        ListNode* head = temp;
        int carry = 0;
        
        while(l1 != NULL  ||  l2 != NULL  || carry){
            
            ListNode* sum = new ListNode();
            temp->next = sum;               // connecting to previous nodes to create linked list
            int add = 0;
            
            if(l1 != NULL){
                add += l1->val;
                l1 = l1->next;
            }
            if(l2 != NULL){
                add += l2->val;
                l2 = l2->next;
            }
            
            if(carry > 0){
                add = add+1;
                carry = 0;
            }
            
            sum->val = add % 10;
            
            if(add > 9){
                carry = 1;    //(or add/10 , it will be 1 only since max add can go is till 18)
                //add = add % 10;
            }
            
            temp = sum;    //temp->next;
        }
        return head->next;
    }
};
