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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1==NULL)
            return l2;
        else if(l2==NULL)
            return l1;
        ListNode* head=new ListNode();
        if(l1->val<=l2->val)
        {
            head->val=l1->val;
            l1=l1->next;
        }
        else
        {
            head->val=l2->val;
            l2=l2->next;
        }
        ListNode* temp=head;
        while(l1 && l2)
        {
            if(l1->val<=l2->val)
            {
                temp->next=l1;
                temp=temp->next;
                l1=l1->next;
            }
            else
            {
                temp->next=l2;
                temp=temp->next;
                l2=l2->next;
            }
        }
        
        while(l1)
        {
            temp->next=l1;
            temp=temp->next;
            l1=l1->next;
        }
        
        while(l2)
        {
            temp->next=l2;
            temp=temp->next;
            l2=l2->next;
        }
        
        return head;
    }
};
