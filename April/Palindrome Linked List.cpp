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
    bool isPalindrome(ListNode* head) {
        vector<int>ar;
        while(head)
        {
            ar.push_back(head->val);
            head=head->next;
        }
        
        vector<int>temp=ar;
        reverse(temp.begin(),temp.end());
        return ar==temp;
    }
};
