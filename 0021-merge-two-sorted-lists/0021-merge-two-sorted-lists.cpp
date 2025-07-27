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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
         ListNode dummy   ;   
         ListNode*newnode = &dummy;
        while(list1&&list2)
        {
            if(list1->val<list2->val)
            {
            newnode->next = list1;
            list1 = list1->next;
           
            }
           else 
            {
            newnode->next = list2;
            list2 = list2->next;
            }
            newnode = newnode->next;
        }
        if(list1) newnode->next = list1;
       else if(list2) newnode->next = list2;
        return dummy.next;
    }
};