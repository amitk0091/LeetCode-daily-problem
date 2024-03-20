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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        
        ListNode* start = list2;
        ListNode* end = list2;
        while(end && end->next){
            end = end->next;
        }
        ListNode* dummy = new ListNode(-1);
        dummy->next = list1;
        ListNode* dum = dummy;
        while(a--){
          dum = dum->next;
        }
        b+=2;
        ListNode* dum2 = dummy;
        while(b--){
               dum2 = dum2->next;
        }
        dum->next = start;
        end->next = dum2;
        return dummy->next;
    }
};