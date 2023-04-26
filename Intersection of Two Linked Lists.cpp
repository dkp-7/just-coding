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



//////////////////////////////////////////////////////////////////////////////////////////////////////


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// Again, using difference of length of lists by changing the list pointers to other nodes when it reaches null, once both the pointer traverse the full nodes of their list, (2) pointer currently at the bigger node will be starting from the(length difference) nodes ahead of the start, so now the pointers are bound to collide naturally where the list intersect each other.


class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        ListNode* p1 = headA;
        ListNode* p2 = headB;
        
        for(int i=1; i<=2; i++){
            while(p1 !=NULL  &&  p2 != NULL){
                p1 = p1->next;
                p2 = p2->next;
            }
            if(p1 == NULL) p1 = headB;
            else p2 = headA;
        }
        
        // (2)
        while(p1 != p2  &&  p1 != NULL  &&  p2 != NULL){
            p1 = p1->next;
            p2 = p2->next;
        }
        if(p1 == p2) return p1;
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
