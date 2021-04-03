/**
 * @file remove-duplicates-from-sorted-list-ii
 * @author Anwar Hossain <anwararif727@gmail.com>
 *
 * @date Saturday April 03 2021
 *
 * @brief 
 */

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* curHead = new ListNode(0);
        ListNode* cur = curHead;

        while (head != NULL) {
            int value = head->val;
            int counter = 0;
            ListNode* temp = head;

            while (head != NULL && value == head->val) {
                head = head->next;
                counter += 1;
            }

            if (counter == 1) {
                cur->next = temp;
                cur = cur->next;
            }
        }

        cur->next = NULL;

        return curHead->next;
    }
};
