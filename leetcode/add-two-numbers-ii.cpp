/**
 * @file add-two-numbers-ii
 * @author Anwar Hossain <anwararif727@gmail.com>
 *
 * @date Saturday April 03 2021
 *
 * @brief 
 */

class Solution {
public:
    int getSize(ListNode *head) {
        ListNode *temp = head;
        int counter = 0;

        while (temp != NULL) {
            counter += 1;
            temp = temp->next;
        }

        return counter;
    }

    ListNode* solve(int fsz, int ssz, ListNode* first, ListNode* second) {
        if (first == NULL && second == NULL) return NULL;
        
        int carry = 0, sum = 0;
        ListNode* cur = new ListNode(0);

        if (fsz == ssz) {
            sum = first->val + second->val;
            cur->next = solve(fsz - 1, ssz - 1, first->next, second->next);
        } else if (fsz > ssz) {
            sum = first->val;
            cur->next = solve(fsz - 1, ssz, first->next, second);
        } else {
            sum = second->val;
            cur->next = solve(fsz, ssz - 1, first, second->next);
        }

        if (cur->next != NULL) {
            int total = cur->next->val;
            carry = total / 10;
            cur->next->val = total % 10;
        }
        
        cur->val = sum + carry;

        return cur;
    }

    ListNode* addTwoNumbers(ListNode* first, ListNode* second) {
        int fsz = getSize(first);
        int ssz = getSize(second);

        ListNode* head = solve(fsz, ssz, first, second);
        if (head->val > 9) {
            int carry = head->val / 10;
            head->val = head->val % 10;
            ListNode* answer = new ListNode(carry);
            answer->next = head;
            return answer;
        }

        return head;
    }
};
