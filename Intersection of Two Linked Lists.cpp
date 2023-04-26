// Leetcode :       160. Intersection of Two Linked Lists  


// Solution using difference of length of given two list

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
        
        int c1=0, c2=0;
        ListNode* headA1 = headA;
        ListNode* headB1 = headB;
        
        while(headA1 != NULL){
            c1++;
            headA1 = headA1->next;
        }
        while(headB1 != NULL){
            c2++;
            headB1 = headB1->next;
        }
        int diff = abs(c1-c2);
        int maxi = max(c1 , c2);
        
        if(maxi == c1){
            for(int i=0; i<diff; i++){
                headA = headA->next;
            }
        }
        else{
            for(int i=0; i<diff; i++){
                headB = headB->next;
            }
        }
        
        while((headA != headB)  &&  headA != NULL  &&  headB != NULL){
            headA = headA->next;
            headB = headB->next;
        }
        if(headA == headB) return headA;
        else return NULL;
    }
};



///////////////////////////////////////////////////////////////////////////////////////////////////////////////


// Solution using Hashing  (T.C : O(sizeof list1 + size of list2) )

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
