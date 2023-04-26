//Leetcode : 141. Linked List Cycle


// Using fast & slow pointer Approach

class Solution {
public:
    bool hasCycle(ListNode *head) {
        
        if(head == NULL)  return false;
        ListNode* fast = head;
        ListNode* slow = head;
        
        while(fast->next != NULL  &&  fast->next->next != NULL){
            
            fast = fast->next->next;
            slow = slow->next;
            
            if(fast == slow)  return true;
        }
        return false;
    }
};


////////////////////////////////////////////////////////////////////////////////

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
 // Using Hashing
 
class Solution {
public:
    bool hasCycle(ListNode *head) {
        
        unordered_set<ListNode*> set;
        while(head != NULL){
            
            if(set.find(head) != set.end()){
                return true;
            }
            set.insert(head);
            head = head->next;
        }
        return false;
    }
};
