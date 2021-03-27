class Solution {
public:
    int wiggleMaxLength(vector<int>& ar) {
        
        int n=ar.size();
        //if(n<=2)
        //    return n;
        int inc=1;
        int dec=1;
        for(int i=0;i<n-1;i++)
        {
            if(ar[i+1]-ar[i]>0)
            {
                inc=dec+1;
            }
            else if(ar[i+1]-ar[i]<0)
            {
                dec=inc+1;
            }
        }
    
        return max(inc,dec);
    }
};
