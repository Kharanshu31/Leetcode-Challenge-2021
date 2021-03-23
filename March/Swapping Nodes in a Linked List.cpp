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
    ListNode* swapNodes(ListNode* head, int k) {
        vector<ListNode*>ar;
        ListNode* temp=head;
        while(temp)
        {
            ar.push_back(temp);
            temp=temp->next;
        }
        
        swap(ar[k-1],ar[ar.size()-k]);
        
        ListNode* n=new ListNode(ar[0]->val);
        ListNode* t=n;
        cout<<" t : "<<t->val<<"\n";
        for(int i=1;i<ar.size();i++)
        {
            ListNode* f=new ListNode(ar[i]->val);
            t->next=f;
            t=t->next;
        }
        
        return n;
    }
};
