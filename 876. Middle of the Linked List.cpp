//  Leetcode :   876. Middle of the Linked List

//Optimal Approach using 2 pointer (fast & slow  ||  tortoise-hare approach)   T.C. : O(N)

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != NULL  &&  fast->next != NULL){

            fast = fast->next;
            fast = fast->next;
            slow = slow->next;
        }
        return slow;
    }
};



/*

// runtime is 0ms (faster than 100% when using while loop instead of for loop, but for small input only)  T.c will be O(n*(n/2))

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        
        ListNode * temp = head;
        int cnt = 1;
        while(temp->next != NULL){
            temp = temp->next;
            cnt++;
        }
        
        int c = 0;
        while(c < cnt/2){
            head = head->next;
            c++;
        }
        return head;
    }
};


*/
