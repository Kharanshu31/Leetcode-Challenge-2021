class Solution {
public:
    int getMaximumGenerated(int n) {
        if(n==0)
            return 0;
        vector<int>ar(102,0);
        ar[0]=0;
        ar[1]=1;
        for(int i=2;i<=n;i++)
        {
            if(i%2==0)
            {
                ar[i]=ar[i/2];
            }
            else
            {
                ar[i]=ar[i/2]+ar[i/2+1];
            }
        }
        
        return *max_element(ar.begin(),ar.end());
    }
};
