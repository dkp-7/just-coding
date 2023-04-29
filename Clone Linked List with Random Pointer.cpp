//LeetCode :        138. Copy List with Random Pointer




/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        
        //Round 1
        // Attach an extra node to the next-> of each node which will become exact copy of this node
        Node* head1 = head;
        Node* front = head;
        while(head1 != NULL){
            
            front = head1->next;    //STORE next of the node to use it later
            Node* copy = new Node(head1->val);
            head1->next = copy;
            copy->next = front;
            head1 = front;
        }
        
        //Round 2
        //Giving each copy node its random value, which will simulate as random of the original list
        head1 = head;
        while(head1 != NULL){
            
            if(head1->random != NULL){
                head1->next->random = head1->random->next;
            }
            head1 = head1->next->next;
        }
        
        
        //Round 3
        //Seprating the attatched copy nodes & stitching them together usiiiing their next to make a clone of original linked list
        //Also, restoring the original linked list to its initaial state
        head1 = head;
        Node* dummyHead = new Node(0);
        Node* copy = dummyHead;
        while(head1 != NULL){
            front = head1->next->next;
            copy->next = head1->next;
            head1->next = front;
            
            copy = copy->next;
            head1 = front;
        }
        
        return dummyHead->next;
    }
};
