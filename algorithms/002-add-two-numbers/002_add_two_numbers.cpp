/**
 * You are given two non-empty linked lists representing two non-negative integers.
 * The digits are stored in reverse order and each of their nodes contain a single digit. 
 * Add the two numbers and return it as a linked list.
 * You may assume the two numbers do not contain any leading zero, except the number 0 itself.
 *
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = NULL;
        ListNode* prev = NULL;
        int carry = 0;
        while (l1 || l2 || carry) {
            int l1_val, l2_val;

            if (l1) {
                l1_val = l1->val;
                l1 = l1->next;
            } else {
                l1_val = 0;
            }

            if (l2) {
                l2_val = l2->val;
                l2 = l2->next;
            } else {
                l2_val = 0;
            }

            int place_sum = l1_val + l2_val + carry;
            int new_val = place_sum % 10;
            prev = createNode(prev, new_val);

            if (!head) {
                head = prev;
            }

            carry = place_sum / 10;
        }

        return head;
    }

private:
    ListNode* createNode(ListNode* prev, int val) {
        ListNode* node = new ListNode(val);

        if (prev) {
            prev->next = node;
        }
        return node;
    }
};
