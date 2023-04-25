//Leetcode :    19. Remove Nth Node From End of List


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

// IN ONE PASS

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        ListNode* fast = head;
        ListNode* slow = head;
        int c = 0;
        while(fast != NULL){
            c++;
            fast = fast->next;
            if(c > n+1){
                slow = slow->next;
            }
        }
        if(c == n) return head->next;
        else{
            slow->next = slow->next->next;
            return head;
        }
    }
};




//////////////////////////////////////////////////////////////////////////////////////////////////////////////



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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        ListNode*temp = head;
        ListNode*temp1 = head;
        int cnt=0;
        while(head != NULL){
            cnt++;
            head = head->next;
        }
        if(cnt == n){
            return temp1->next;
        }
        for(int i=1; i<cnt-n; i++){
            temp = temp->next;
        }
        temp->next = temp->next->next;
        return temp1;
    }
};
