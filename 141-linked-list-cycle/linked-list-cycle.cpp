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
    bool hasCycle(ListNode *head) {
        // if(head==NULL) return false;
        //slow pointer fast pointer
        ListNode* pre = new ListNode(-1);
        pre->next =head;
        ListNode* slow = pre;
        ListNode* fast = pre->next;
        while(slow!=fast){
            if(fast==NULL || fast->next==NULL || fast->next->next==NULL) return false;
            fast= fast->next->next;
            slow=slow->next;
        }
        // if(slow==fast) cout<<"je";
        return true;
    }
};