//Leetcode :    21. Merge Two Sorted Lists

//IN-PLACE SOLUTION without using extra space
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        if(list1 == NULL) return list2;
        if(list2 == NULL) return list1;
        
        ListNode* head = list1;
        if(list1->val > list2->val){
            head = list2;
            swap(list1 , list2);
            //head = list1;
        }
        
        while(list1 != NULL  &&  list2 != NULL){
            
            ListNode* temp = NULL;
            while(list1 != NULL  &&  list2 != NULL  &&  (list1->val <= list2->val)){
                temp = list1;
                list1 = list1->next;
            }
            temp->next = list2;
            swap(list1 , list2);
        }
        return head;
    }
};


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//Solution using extra space / linked list
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        struct ListNode* d = new ListNode();
        struct ListNode* head = d;
        
        while(list1 != NULL  &&  list2 != NULL){
            
            struct ListNode* n = new ListNode();
            
            if(list1->val  <=  list2->val){
                n->val = list1->val;
                list1 = list1->next;
                d->next = n;
                d = d->next;
            }
            else{
                n->val = list2->val;
                list2 = list2->next;
                d->next = n;
                d = d->next;
            }
        }
        
        while(list1 != NULL){
            struct ListNode* n = new ListNode();
            n->val = list1->val;
            list1 = list1->next;
            d->next = n;
            d = d->next;
        }
        while(list2 != NULL){
            struct ListNode* n = new ListNode();
            n->val = list2->val;
            list2 = list2->next;
            d->next = n;
            d = d->next;
        }
        head = head->next;
        return head;
    }
};
