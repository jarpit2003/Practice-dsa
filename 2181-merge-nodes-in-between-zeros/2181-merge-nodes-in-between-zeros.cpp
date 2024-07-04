class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        ListNode dummy, *tail = &dummy;
        while (head) {
            if (head->val == 0) head = head->next; // skip leading `0`
            if (!head) break;
            int sum = 0;
            while (head->val != 0) { // sum numbers before the next `0`
                sum += head->val;
                head = head->next;
            }
            tail->next = new ListNode(sum); // append `sum`
            tail = tail->next;
        }
        return dummy.next;
    }
};