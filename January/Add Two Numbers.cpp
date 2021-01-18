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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* t=l1;
        string s1="";
        while(t)
        {
            s1+=(t->val+'0');
            t=t->next;
        }
        
        t=l2;
        string s2="";
        while(t)
        {
            s2+=(t->val+'0');
            t=t->next;
        }
        int n=s1.length();
        int m=s2.length();
        if(s1.length()>s2.length())
        {
            for(int i=0;i<n-m;i++)
                s2+="0";
        }
        else if(s2.length()>s1.length())
        {
            for(int i=0;i<m-n;i++)
                s1+="0";
        }
        reverse(s1.begin(),s1.end());
        reverse(s2.begin(),s2.end());
        cout<<s1<<"  "<<s2<<"\n";
        int i=s1.length()-1,j=s2.length()-1;
        int c=0;
        string ans="";
        while(i>=0 && j>=0)
        {
            int x=s1[i]-'0';
            int y=s2[i]-'0';
            int z=x+y;
            int a=z;
            a%=10;
            cout<<" c : "<<c<<" z : "<<z<<"\n";
            int b=a+c;
            b=b%10;
            ans+=(b+'0');
            if(c+z>=10)
                c=1;
            else
                c=0;
            i--;j--;
        }
        if(c!=0)
            ans+="1";
        cout<<" ans : "<<ans<<"\n";        
        //reverse(ans.begin(),ans.end());
        //cout<<" ans : "<<ans<<"\n";
        ListNode* head=new ListNode();
        ListNode* cur=head;
        for(int i=0;i<ans.length();i++)
        {
            if(i==0)
            {
                head->val=ans[i]-'0';
                continue;
            }
            ListNode* f=new ListNode(ans[i]-'0');
            cur->next=f;
            cur=cur->next;
        }
        return head;
    }
};
