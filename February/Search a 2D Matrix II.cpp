class Solution {
public:
    
    bool linear(vector<vector<int>>& ar, int target) {
        //O(m+n)
        int i=0;
        int j=ar[0].size()-1;
        while(i<ar.size() && j>=0)
        {
            cout<<ar[i][j]<<"\n";
            if(ar[i][j]==target)
                return true;
            if(ar[i][j]>target)
            {
                j--;
            }
            else
            {
                i++;
            }
        }
        return false;
    }
    
    bool binary(vector<vector<int>>& ar, int target) {
        //O(nlogm)
        int n=ar.size();
        int m=ar[0].size();
        for(int i=0;i<n;i++)
        {
            if(ar[i][0]>target)
                break;
            //vector<int>f=ar[i];
            int l=0;
            int h=m-1;
            while(l<=h)
            {
                int mid=(l+h)/2;
                if(ar[i][mid]==target)
                    return true;
                if(ar[i][mid]<target)
                    l=mid+1;
                else
                    h=mid-1;
            }
        }
        return false;
    }
    
    bool searchMatrix(vector<vector<int>>& ar, int target) {
        return binary(ar,target);
    }
};
