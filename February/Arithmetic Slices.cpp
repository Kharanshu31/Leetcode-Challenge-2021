class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& a) {
        int n=a.size();
        int i=0;
        int ans=0;
        while(i<n-2)
        {
            int j=i;
            while(j<n-2 && a[j+1]-a[j]==a[j+2]-a[j+1])
            {
                j++;
            }
            int t=j-i;
            ans+=((t+1)*t)/2;
            i=j+1;
        }
        return ans;
    }
};
