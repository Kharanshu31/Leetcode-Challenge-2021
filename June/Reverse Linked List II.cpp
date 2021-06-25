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
    ListNode* reverse(ListNode*root,ListNode*end)
    {
        ListNode*prev=NULL;
        ListNode*cur=root;
        while(cur && cur!=end)
        {
            //cout<<" cur : "<<cur->val<<"\n";
            ListNode*t=cur->next;
            cur->next=prev;
            
            prev=cur;
            cur=t;
        }
        return prev;
    }
    
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left==right)
            return head;
        
        auto temp=head;
        left--;
        ListNode* prev=NULL;
        while(left>0 && temp)
        {
            left--;
            prev=temp;
            temp=temp->next;
        }
        
        auto temp2=head;
        ListNode* prev2=NULL;
        while(right>0 && temp2)
        {
            right--;
            prev2=temp2;
            temp2=temp2->next;
        }
        auto x=temp2;
        if(prev)
            prev->next=NULL;
        prev2->next=NULL;
        
        auto t=reverse(temp,temp2);
        if(prev)
            prev->next=t;
        else
            head=t;
        auto f=t;
        while(f->next)
            f=f->next;
        f->next=x;
        
        return head;
        
    }
};
