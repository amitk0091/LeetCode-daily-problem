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
    ListNode* reverseList(ListNode* head) {
        if (head == NULL)
            return head;
        ListNode* curr = head;
        ListNode* prev = NULL;
        while (curr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    ListNode* doubleIt(ListNode* head) {
        ListNode* newh = reverseList(head);
        ListNode* temp = newh;
        int pre = 0;
        ListNode* tail = NULL;
        while (temp) {
            tail = temp;
            int k = (2 * temp->val + pre) % 10;
            pre = (2 * temp->val + pre) / 10;
            temp->val = k;
            temp = temp->next;
        }
        if (pre) {
            ListNode* extra = new ListNode(pre);
            tail->next = extra;
        }
        return (reverseList(newh));
    }
};