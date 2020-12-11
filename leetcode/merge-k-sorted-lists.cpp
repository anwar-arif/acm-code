class Solution {
public:
	ListNode* merge(ListNode *first, ListNode *second) {
		ListNode* answer = new ListNode(0);
		ListNode* cur = answer;
		while (first != NULL && second != NULL) {
			if (first->val < second->val) {
				cur->next = first;
				first = first->next;
			} else {
				cur->next = second;
				second = second->next;
			}
            cur = cur->next;
		}
		(first != NULL) ? cur->next = first : cur->next = second;
		return answer->next;
	}

	ListNode* mergeKLists(vector<ListNode*>& lists) {
		int len = (int) lists.size();
		if (len == 0) return NULL;
        int interval = 1;
		while (interval < len) {
			for (int i = 0; i + interval < len; i += 2 * interval) {
				lists[i] = merge(lists[i], lists[i + interval]);
			}
			interval += interval;
		}
		return lists[0];
	}
};

