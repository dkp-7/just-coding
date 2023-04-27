//LEETCODE:   234. Palindrome Linked List



class Solution {
public:
    bool isPalindrome(ListNode* head) {
        vector<int> ele;
        ListNode* temp = head;
        int c= 0;
        while(temp != NULL){
            ele.push_back(temp->val);
            temp = temp->next;
            c++;
        }
        
        for(int i=0; i<c/2; i++){
            
            if(head->val != ele[c-1-i]){
                return false;
            }
            head = head->next;
        }
        return true; 
    }
};


// T.C. : O(N)+O(N/2)       S.C.: O(N)
