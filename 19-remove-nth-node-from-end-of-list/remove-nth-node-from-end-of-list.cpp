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
    ListNode* traverseList(ListNode* head,int& n){
        if(head==NULL) return NULL;
        ListNode* next = traverseList(head->next,n);
        n--;
        if(n==0) return next;
        head->next = next;
        return head;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        return traverseList(head,n);
    }
};