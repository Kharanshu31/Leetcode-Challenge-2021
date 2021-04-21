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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode*t=head;
        int sz=0;
        while(t)
        {
            sz++;
            t=t->next;
        }
        
        t=head;
        ListNode*prev=NULL;
        int ct=1;
        while(t)
        {
            if(ct==sz-n+1)
            {
                cout<<t->val<<"\n";
                if(!prev)
                {
                    ListNode*p=head;
                    head=head->next;
                    p->next=NULL;
                }
                else
                {
                    cout<<prev->val<<"\n";
                    prev->next=NULL;
                    if(t->next)
                        prev->next=t->next;
                }
            }
            prev=t;
            t=t->next;
            ct++;
        }
        
        return head;
    }
};
