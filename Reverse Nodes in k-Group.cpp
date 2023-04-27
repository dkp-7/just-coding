// Leetcode :     25. Reverse Nodes in k-Group


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
        // pre->next will always point to deemed to be current(curr)
        // curr->next will always be storing the nex->next
        // nex->next will retrieve its next from curr->next once it completes reversing direction b/w 2 nodes 

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        ListNode* temp = head;
        int c=0;
        while(temp != NULL){
            c++;
            temp = temp->next;
        }
        
        ListNode* dummy = new ListNode();
        dummy->next = head;
        ListNode* pre = dummy;
        ListNode* curr;
        ListNode* nex;
        
        while(c >= k){
            curr = pre->next;
            nex = curr->next;
            
            for(int p=1; p<k; p++){
                
                curr->next = nex->next;
                nex->next = pre->next;
                pre->next = nex;
                nex = curr->next;
            }
            pre = curr;
            c = c-k;
        }
        return dummy->next;
    }
};
