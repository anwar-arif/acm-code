/**
 * @file remove-nth-node-from-end-of-list
 * @author Anwar Hossain <anwararif727@gmail.com>
 *
 * @date Saturday April 03 2021
 *
 * @brief 
 */

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* answer = head;
        ListNode* pre = NULL;
        int counter = 0;
        
        while (head->next != NULL) {
            head = head->next;
            counter += 1;
            if (counter >= n) {
                pre = (pre == NULL) ? answer : pre->next;
            }
        }

        (pre == NULL) ? answer = answer->next : pre->next = pre->next->next;

        return answer;
    }
};