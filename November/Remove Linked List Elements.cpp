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
    ListNode* removeElements(ListNode* head, int val) {
        if(!head)
          return head;
        ListNode *temp=head;
        ListNode *prev=NULL;
        if(head->val==val)
        {
            temp=head->next;
            head=temp;
        }
        while(temp)
        {
            prev=temp;
            while(temp->next && temp->next->val==val)
            {
                //prev=temp;
                temp=temp->next;
            }
            prev->next=temp->next;
            temp=temp->next;
        }
        
        return head;
    }
};
