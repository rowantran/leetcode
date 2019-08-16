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
        while (l1->next && l2->next) {
            prev = createNode(prev, l1->val + l2->val);
            if (!head) {
                head = prev;
            }

            l1 = l1->next;
            l2 = l2->next;
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
