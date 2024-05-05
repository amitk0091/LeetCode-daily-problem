/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        //  node = node->next;
        if(node->next){
            node->val = node->next->val;
            node->next = node->next->next;
        }
        else node=NULL;
    }
};