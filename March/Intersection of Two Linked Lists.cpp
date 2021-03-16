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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        map<ListNode *,bool>vis;
        ListNode * temp=headA;
        while(temp)
        {
            vis[temp]=true;
            temp=temp->next;
        }
        
        ListNode * temp2=headB;
        while(temp2)
        {
            if(vis[temp2])
                return temp2;
            temp2=temp2->next;
        }
        return NULL;
    }
};
