class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n=nums.size();
        int low=0;
        int high=n-1;
        while(low<=high)
        {
            int mid=(low+high)/2;
            int prev=INT_MIN;
            int next=INT_MIN;
            if(mid-1>=0)
                prev=nums[mid-1];
            if(mid+1<n)
                next=nums[mid+1];
            
            if(nums[mid]>=prev && nums[mid]>=next)
                return mid;
            
            if(nums[mid]<prev)
                high=mid-1;
            else
                low=mid+1;
            
        }
        
        return low;
    }
};
