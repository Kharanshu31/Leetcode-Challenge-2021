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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head)
            return NULL;
        if(!head->next)
            return head;
        ListNode* cur=new ListNode();
        ListNode* x=cur;
        ListNode* temp=head;
        while(temp)
        {
            ListNode* t=temp;
            while(t && t->next && t->val==t->next->val)
                t=t->next;
            if(t && temp && temp==t)
            {
                ListNode* prev=new ListNode(temp->val);
                x->next=prev;
                x=x->next;
            }
            if(t)
                temp=t->next;
        }
        
        return cur->next;
    }
};
