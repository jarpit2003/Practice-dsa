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
     ListNode*curr = head;
     int cnt = 0;
     while(curr)
     {
        cnt++;
        curr = curr->next;
     }   
     int idx = cnt-n+1;
     if(idx==1) return head->next;
    ListNode*prev = head;
    for(int i =0;i<idx-2;i++)
    {
        prev = prev->next;
    }
    ListNode*todel = prev->next;
    prev->next = prev->next->next;
    delete todel;
    return head;
    }
};