/**
 * @file add-two-numbers
 * @author Anwar Hossain <anwararif727@gmail.com>
 *
 * @date Friday April 02 2021
 *
 * @brief 
 */
class Solution {
public:
    
    ListNode* solveRest(ListNode* result, ListNode* current, int carry) {
        while (current != NULL) {
            int total = current->val + carry;
            int value = total % 10;
            carry = total / 10;

            result->next = new ListNode(value);
            result = result->next;
            current = current->next;
        }
        
        if (carry) {
            result->next = new ListNode(carry);
        }
        
        return result;
    }
    
    ListNode* add(ListNode *first, ListNode* second) {
        ListNode* head = new ListNode(0);
        ListNode* result = head;
        int carry = 0;
        
        while (first != NULL && second != NULL) {
            int total = first->val + second->val + carry;
            int value = total % 10;
            carry = total / 10;
            
            result->next = new ListNode(value);
            result = result->next;
            
            first = first->next;
            second = second->next;
        }
        
        result = solveRest(result, first == NULL ? second : first, carry);
        
        return head->next;
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        return add(l1, l2);
    }
};
