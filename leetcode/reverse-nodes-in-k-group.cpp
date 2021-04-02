/**
 * @file reverse-nodes-in-k-group
 * @author Anwar Hossain <anwararif727@gmail.com>
 *
 * @date Friday April 02 2021
 *
 * @brief 
 */

class Solution {
public:
    ListNode* reverse(ListNode *head, int k) {
        ListNode *cur = head;
        ListNode *pre = NULL;

        while (k--) {
            ListNode *temp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = temp;
        }

        return pre;
    }

    ListNode* solve(ListNode *head, int k) {
        int total = 0;
        ListNode* temp = head;
        while (temp != NULL && total < k) {
            total += 1;
            temp = temp->next;
        }

        if (total < k) return head;

        ListNode *tail = head;
        ListNode* reversedHead = reverse(head, k);
        tail->next = solve(temp, k);

        return reversedHead;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == NULL) return head;
        return solve(head, k);
    }
};