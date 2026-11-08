   // LeetCode 23 - Merge k Sorted Lists
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode* tail = &dummy;
        while (l1 != nullptr && l2 != nullptr) {
            if (l1->val <= l2->val) {
                tail->next = l1;
                l1 = l1->next;
            } else {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }
        if (l1 != nullptr) {
            tail->next = l1;
        } else {
            tail->next = l2;
        }
        return dummy.next;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) {
            return nullptr;
        }
        int n = lists.size();
        while (n > 1) {
            int newN = 0;
            for (int i = 0; i < n; i += 2) {
                if (i + 1 < n) {
                    lists[newN++] = mergeTwoLists(lists[i], lists[i + 1]);
                } else {
                    lists[newN++] = lists[i];
                }
            }
            n = newN;
        }
        return lists[0];
    }
};
