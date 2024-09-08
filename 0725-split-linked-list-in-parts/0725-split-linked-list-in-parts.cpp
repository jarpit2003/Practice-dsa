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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        // Step 1: Calculate the length of the linked list
        int length = 0;
        ListNode* current = head;
        while (current) {
            length++;
            current = current->next;
        }

        // Step 2: Determine the size of each part
        int partSize = length / k;  // Minimum size of each part
        int extraNodes = length % k;  // Extra nodes to distribute

        // Step 3: Create the result vector
        vector<ListNode*> result(k, nullptr);
        current = head;

        for (int i = 0; i < k && current; i++) {
            result[i] = current;  // The start of the i-th part
            int currentPartSize = partSize + (extraNodes > 0 ? 1 : 0);  // Determine size of current part
            extraNodes--;

            // Move to the end of the current part
            for (int j = 1; j < currentPartSize; j++) {
                current = current->next;
            }

            // Split the list
            ListNode* nextPart = current->next;
            current->next = nullptr;  // Cut off the current part
            current = nextPart;
        }

        return result;
    }
};
