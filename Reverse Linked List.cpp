// Leetcode :    206. Reverse Linked List

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
    ListNode* reverseList(ListNode* head) {
        
        ListNode *temp = NULL;
        
        while(head != NULL){
            
            ListNode *nn = head->next;              // here 'nn' stands for next node
            head->next = temp;
            temp = head;
            head = nn;
        }
        return temp;
    }
};


////////////////////////////////////////////////////////////////////////////////////////////////////////

/*
// Recursive Approach

class Solution {
public:
    
    void helper(ListNode* &head , ListNode* &temp){
        
        if(head == NULL){
            return;
        }
        ListNode* nn = head->next;
        head->next = temp;
        temp = head;
        head = nn;
        helper(head , temp);
        
    }
    
    ListNode* reverseList(ListNode* head) {
        
        ListNode*  temp = NULL;
        helper(head , temp);
        return temp;
    }
};

*/
