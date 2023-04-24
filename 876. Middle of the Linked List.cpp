//  Leetcode :   876. Middle of the Linked List
//Most optimal: runtime is 0ms (faster than 100% when using while loop instead of for)

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
