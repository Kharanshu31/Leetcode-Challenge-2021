class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size()-1;
        int k=nums.size()-1;
        while(n>0 && nums[n-1]>=nums[n])
            n--;
        for(int j=n;j<k;j++,k--)
        {
            swap(nums[j],nums[k]);
        }
        if(n>0)
        {
            k=n--;
            while(nums[k]<=nums[n])
                k++;
            swap(nums[k],nums[n]);
        }
    }
};
