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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* answer = NULL;
        ListNode* current = answer;
        ListNode* curr = head;
        while (curr != NULL) {
            if (curr->val != val) {
                ListNode* ahead = new ListNode(curr->val);
                if (answer == NULL) {
                    answer = ahead;
                    current = ahead;
                } else {
                    current->next = ahead;
                    current = ahead;
                }
            }
            curr = curr->next;
        }
        return answer;
    }
};