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
    ListNode* partition(ListNode* head, int x) {
        ListNode*temp=head;
        ListNode*prev=NULL;
        while(temp && temp->val<x)
        {
            prev=temp;
            temp=temp->next;
        }
        if(!temp)
            return head;
        ListNode*cur=temp;
        ListNode*use=prev;
        while(cur)
        {
            if(cur->val<x)
            {
                cout<<" cur : "<<cur->val<<"\n";
                if(prev)
                {
                    ListNode*c=cur;
                    //cout<<"prev : "<<prev->val<<"\n";
                    prev->next=NULL;
                    if(use)
                    {
                        //cout<<" use : "<<use->val<<"\n";
                        use->next=NULL;
                        if(cur->next)
                            use->next=cur->next;
                    }
                    prev->next=c;
                    prev=c;
                    c->next=temp;
                }
                else
                {
                    ListNode*c=cur;
                    if(use)
                    {
                        use->next=NULL;
                        if(cur->next)
                            use->next=cur->next;
                    }
                    c->next=NULL;
                    c->next=head;
                    head=c;
                    prev=c;
                }
            }
            //ListNode*f=head;
            // while(f)
            // {
            //     cout<<f->val<<"  ";
            //     f=f->next;
            // }
            // cout<<"\n";
            use=cur;
            cur=cur->next;
            
        }
        return head;
    }
};
