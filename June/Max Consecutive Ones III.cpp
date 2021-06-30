class Solution {
public:
    int longestOnes(vector<int>& ar, int m) {
        int n=ar.size();
        if(m==0)
        {
            int ans=0;
            int ct=0;
            for(int i=0;i<n;i++)
            {
                if(ar[i]==0)
                {
                    ans=max(ans,ct);
                    ct=0;
                }
                else
                {
                    ct++;
                }
            }
            ans=max(ans,ct);
            return ans;
        }
        
        queue<int>q;
        int ans=0;
        int prev=0;
        for(int i=0;i<n;i++)
        {
            if(ar[i]==0)
            {
                if(q.size()>=m)
                {
                    if(q.empty())
                        prev=i+1;
                    else
                    {
                        prev=q.front()+1;
                        q.pop();
                    }
                }
                q.push(i);
            }
            //cout<<i<<"  "<<prev<<"\n";
            ans=max(ans,i-prev+1);
        }
        return ans;
    }
};
