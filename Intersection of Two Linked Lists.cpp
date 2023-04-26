// Leetcode :       160. Intersection of Two Linked Lists  


//Brute force approach

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        while(headA != NULL){
            ListNode* tempB = headB;
            while(tempB != NULL){
                if(headA == tempB){
                    return headA;
                }
                tempB = tempB->next;
            }
            headA = headA->next;
        }
       return NULL;
    }
};
