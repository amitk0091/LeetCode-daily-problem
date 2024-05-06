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
    int mx = 0;
    ListNode* reverseLinkedList(ListNode* head) {
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
    ListNode* removeNodes(ListNode* head) {

        // reverse a linked list
        if (head == NULL)
            return NULL;
        ListNode* newh = reverseLinkedList(head);
        int pre = newh->val;
        ListNode* temp = newh;
        ListNode* prev = newh;
        while (temp) {
            pre = max(pre, temp->val);
            if (temp->val < pre) {
                prev->next = temp->next;
            }
            else prev = temp;
            temp = temp->next;
        }
        ListNode* newH2 = reverseLinkedList(newh);
        return newH2;
    }
};

//    if(head==NULL) return NULL;
//    head->next = removeNodes(head->next);
//    mx= max(mx,head->val);
//    if(mx>head->val) return head->next;
//    return head;