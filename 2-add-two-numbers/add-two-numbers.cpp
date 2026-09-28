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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *temp1 = l1, *temp2 = l2;
        ListNode dummy(0);
        ListNode* prev = &dummy;
        int carry = 0;
        while (temp1 && temp2 ) {
            int value = temp1->val + temp2->val + carry;
            ListNode* curr = new ListNode(value % 10);
            carry = value / 10;
            prev->next = curr;
            prev = curr;
            temp1=temp1->next;
            temp2=temp2->next;
        }
        while (temp1 ) {
            int value = temp1->val +  carry;
            ListNode* curr = new ListNode(value % 10);
            carry = value / 10;
            prev->next = curr;
            prev = curr;
            temp1=temp1->next;
            
        }
        while (temp2 ) {
            int value = temp2->val +  carry;
            ListNode* curr = new ListNode(value % 10);
            carry = value / 10;
            prev->next = curr;
            prev = curr;
            temp2=temp2->next;
            
        }
        if(carry){
            ListNode* curr = new ListNode(carry);
            prev->next = curr;
        
        }
        
        return dummy.next;

    }
};