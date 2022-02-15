class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=0,j=1;
        while(i<nums.size())
        {
            j=i+1; 
            while(j<nums.size() && nums[j]==nums[i])
                j++;
            while(j-i>2)
            {   
                nums.erase(nums.begin()+j-1);
                j--;
            }
            //for(int k=0;k<nums.size();k++)
            //    cout<<nums[k]<<"  ";
            //cout<<"\n";
            i=j;
        }
        
        return nums.size();
    }
};
