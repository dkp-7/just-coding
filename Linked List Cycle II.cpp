// Leetcode :     142. Linked List Cycle II

//Most optimal approach

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        
        if(head == NULL  ||  head->next == NULL) return NULL;
        ListNode* fast = head;
        ListNode* slow = head;
        
        while(fast->next != NULL  &&  fast->next->next !=NULL){
            fast = fast->next->next;
            slow = slow->next;
            
            if(fast == slow){
                fast = head;
                while(fast != slow){
                    fast= fast->next;
                    slow = slow->next;
                }
                return fast;  //return slow;
            }
        }
        // After 1st collision set the past pointer to head sgsin & move both fast & slow ptr now.. one step at a time,
        //their 2nd collision will be the starting node of the linked list loop (to know why : see Floyd's Cycle-Finding algorithm)
        
        return NULL;
    }
};



////////////////////////////////////////////////////////////////////////////////////////////////////////////


// Using Hashing

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        
        unordered_set<ListNode*> hashset;
        while(head != NULL){
            
            if(hashset.find(head) != hashset.end()){
                return head;
            }
            hashset.insert(head);
            head = head->next;
        }
        return NULL;
    }
};
