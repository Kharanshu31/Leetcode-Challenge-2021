class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int n=nums.size();
        if(n<=2)
            return true;
        int pos=-1;
        int ct=0;
        for(int i=0;i<n-1;i++)
        {
            if(nums[i]>nums[i+1])
            {
                pos=i;
                ct++;
                if(ct>1)
                    return false;
            }
        }
        if(ct==0 || pos==0 || pos==n-2)
            return true;
        if(ct==1)
        {
            if(nums[pos-1]<=nums[pos+1] || nums[pos]<=nums[pos+2])
                return true;
        }
        
        return false;
    }
};
