class Solution {
public:
    
    int n;
    bitset<16>vis;
    bool solve(vector<int>&match,int k,int target,int i,int cur)
    {
        if(k==1)
            return true;
        if(cur==target)
        {
            return solve(match,k-1,target,0,0);
        }
        if(cur>target)
            return false;
        
        for(int j=i;j<n;j++)
        {
            if(!vis[j])
            {
                cur+=match[j];
                vis[j]=true;
                if(solve(match,k,target,j+1,cur))
                    return true;
                cur-=match[j];
                vis[j]=false;
            }
        }
        
        return false;
        
    }
    
    bool makesquare(vector<int>& match) {
        //Similar to partition in k equal subset sum , k=4
        sort(match.begin(),match.end(),greater<int>());
        n=match.size();
        int k=4;
        int sum=0;
        for(int i=0;i<n;i++)
            sum+=match[i];
        if(sum%4!=0)
            return false;
        return solve(match,k,sum/4,0,0);

    }
};
