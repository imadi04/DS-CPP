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
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL)
            return NULL;
        if(!head->next)
            return head;
        ListNode *t1=head->next;
        //ListNode *t;
        head->next=swapPairs(head->next->next);
        //head->next=t;
        t1->next=head;
        //head=t1; 
        return t1;
    }
};