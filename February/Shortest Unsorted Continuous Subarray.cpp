class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int>temp=nums;
        sort(nums.begin(),nums.end());
        int left=-1;
        for(int i=0;i<nums.size();i++)
        {
            if(temp[i]!=nums[i])
            {
                left=i;
                break;
            }
        }
        
        if(left==-1)
            return 0;
        
        int right=-1;
        for(int i=nums.size()-1;i>=0;i--)
        {
            if(temp[i]!=nums[i])
            {
                right=i;
                break;
            }
        }
        
        return right-left+1;
        
    }
};
