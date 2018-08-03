/**
 * Definition of singly-linked-list:
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *        this->val = val;
 *        this->next = NULL;
 *     }
 * }
 */

class Solution {
public:
    /**
     * @param head: the first Node
     * @return: the answer after plus one
     */
    ListNode * plusOne(ListNode * head) {
        // Write your code here
        if( head == NULL ) return NULL;
        std::stack<ListNode*> stk;
        int carry = 1;
        int sum;
        
        // push to stack
        ListNode* curr = head;
        while( curr != NULL )
        {
            stk.push(curr);
            curr = curr->next;
        }
        
        while( !stk.empty() )
        {
            curr = stk.top();
            stk.pop();
            sum = curr->val + carry;
            carry = sum / 10;
            curr->val = sum % 10;
        }
        
        ListNode* new_head = head;
        if( carry != 0 ) 
        {
            new_head = new ListNode(carry);
            new_head->next = head;
        }
        return new_head;
        
    }
};
