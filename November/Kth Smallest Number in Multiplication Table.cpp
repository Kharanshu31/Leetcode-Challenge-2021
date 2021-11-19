class Solution {
public:
    int findKthNumber(int m, int n, int k) {
        int low=0;
        int high=3e8;
        while(low<=high)
        {
            int mid=(high+low)/2;
            int cur=0;
            for(int i=1;i<=n;i++)
            {
                cur+=min(m,mid/i);
            }
            if(cur<k)
                low=mid+1;
            else
                high=mid-1;
        }
        return low;
    }
};
