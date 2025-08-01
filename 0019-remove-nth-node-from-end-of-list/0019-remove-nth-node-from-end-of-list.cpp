/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy(0,head);
        ListNode*slow = &dummy;
        ListNode*fast = &dummy;
        for(int i =0;i<n;i++)
        {
            fast = fast->next;
        }
        while(fast->next!=NULL)
        {
            slow = slow->next;
            fast = fast->next;
        }
        ListNode*todelete = slow->next;
        slow->next = slow->next->next;
        delete todelete;
        return dummy.next;
    }
};