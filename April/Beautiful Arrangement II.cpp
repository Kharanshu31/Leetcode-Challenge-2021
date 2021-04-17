class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<int>ans;
        if(k==1)
        {
            for(int i=1;i<=n;i++)
                ans.push_back(i);
            return ans;
        }
        ans.push_back(1);
        k--;
        int s=2;
        int e=n;
        vector<bool>vis(n+1,false);
        bool flag=false;
        for(int i=2;i<=n;i++)
        {
            if(k<=0)
                break;
            if(i%2==0)
            {
                ans.push_back(e);
                e--;
                k--;
                flag=true;
            }
            else
            {
                ans.push_back(s);
                s++;
                k--;
                flag=false;
            }
        }
        cout<<e<<"  "<<s<<"   "<<flag;
        if(flag)
        {
            for(int i=e;i>=s;i--)
                ans.push_back(i);
        }
        else
        {
            for(int i=s;i<=e;i++)
                ans.push_back(i);
        }
        return ans;
    }
};
