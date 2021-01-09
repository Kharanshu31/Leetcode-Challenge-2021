class Solution {
public:
    int findKthPositive(vector<int>& ar, int k) {
        vector<int>ans;
        int ct=1;
        for(int i=0;i<ar.size();)
        {
            if(ar[i]!=ct)
            {
                ans.push_back(ct);
                ct++;
            }
            else
            {
                i++;
                ct++;
            }
        }
        
        if(ans.size()<k)
        {
            return ct+k-1-ans.size();
        }
        else
        {
            return ans[k-1];
        }
    }
};
