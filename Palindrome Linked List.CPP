//LEETCODE:   234. Palindrome Linked List

// Optimised approach, it doesn't use extra space. T.C. is O(N/2) to find middle + O(n/2) to reverse 2nd half of list + O(n/2) to check if it is palindrome or not

class Solution {
public:
    bool isPalindrome(ListNode* head) {

        ListNode* fast = head;
        ListNode* slow = head;
        int c = 0;
        //finding middle to reverse the linked list from middle(slow ptr ) to end of the linked list 
        
        while(fast->next != NULL  &&  fast->next->next != NULL){     //if we do not use both condition fast may point to NULL, which may result in error
            slow = slow->next;
            fast = fast->next->next;
            c++;
        }
        
        //(slow will always move 1 step forward before reversing the remaining linked list, doesn't matter whether the length is even or odd, check it manually by dry run to understand 'why')
        slow = slow->next;
        c++;
        ListNode* temp = NULL;
        
        while(slow != NULL){
            ListNode* temp1 = slow->next;
            slow->next = temp;
            temp = slow;
            slow = temp1;
            c++;
        }
        ListNode* revHead = temp;
        
        for(int i=0; i<c/2; i++){
            
            if(revHead->val != head->val){
                return false;
            }
            revHead = revHead->next;
            head = head->next;
        }
        return true;
    }
};

///////////////////////////////////////////////////////////////////////////////////////////////////////////

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
