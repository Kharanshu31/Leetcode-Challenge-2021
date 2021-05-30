class Solution {
public:
    int maximumUniqueSubarray(vector<int>& ar) {
        int n=ar.size();
        int ans=0;
        vector<int>h(1e4+1,-1);
        vector<int>pre(n,0);
        for(int i=0;i<n;i++)
        {
            if(i==0)
                pre[i]=ar[i];
            else
                pre[i]=ar[i]+pre[i-1];
        }
        int i=0;
        int start=-1;
        int init=0;
        while(i<n)
        {
            if(h[ar[i]]>start)
            {
                start=h[ar[i]];
                init=pre[start];
            }
            h[ar[i]]=i;
            ans=max(ans,pre[i]-init);
            i++;
        }
        
        return ans;
    }
};
