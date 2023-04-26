// Leetcode :       160. Intersection of Two Linked Lists  


//Optimal Solution using Hashing  (T.C : O(sizeof list1 + size of list2) )

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        unordered_set<ListNode*> set;
        
        while(headA != NULL){
            set.insert(headA);
            headA = headA->next;
        }
        while(headB != NULL){
            if(set.find(headB) != set.end()){
                return headB;
            }
            headB = headB->next;
        }
        return NULL;
    }
};




/////////////////////////////////////////////////////////////////////////////////////////////////////////

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
