class Solution {
public:
    
    static bool cmp(pair<int,pair<int,int>>&a,pair<int,pair<int,int>>&b)
    {
        return a.second.first<b.second.first;
    }
    
    int binary(vector<pair<int,pair<int,int>>>&t,int i,int n)
    {
        int low=0;
        int high=i;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(t[mid].second.first<=t[i].first)
            {
                low=mid+1;
            }
            else
            {
                high=mid-1;
            }
        }
        return low-1;
    }
    
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n=profit.size();
        vector<pair<int,pair<int,int> > >times;
        for(int i=0;i<n;i++)
        {
            times.push_back({startTime[i],{endTime[i],profit[i]}});
        }
        
        sort(times.begin(),times.end(),cmp);
        vector<int>dp(n,0);
        dp[0]=times[0].second.second;
        for(int i=1;i<n;i++)
        {
            dp[i]=dp[i-1];
            int ind=binary(times,i,n);
            //cout<<" ind : "<<ind<<"\n";
            if(ind!=-1)
            {
                dp[i]=max(dp[i],dp[ind]+times[i].second.second);
            }
            else
            {
                dp[i]=max(dp[i],times[i].second.second);
            }
        }
        
        // for(int i=0;i<n;i++)
        //     cout<<dp[i]<<"  ";
        return dp[n-1];
        
    }
};
