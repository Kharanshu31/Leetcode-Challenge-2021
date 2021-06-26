class Solution {
public:
    void merge(vector<pair<int,int> >&v,vector<int>&ans,int i,int mid,int j)
    {
        int n=j-i+1;
        mid++;
        vector<pair<int,int> >temp(n);
        int l=i;
        int r=mid;
        int k=0;
        //SORTING IN DESCENDING ORDER
        while(l<mid && r<=j)
        {
            if(v[l].first<=v[r].first)
            {
                temp[k++]=v[r++];
            }
            else
            {
                ans[v[l].second]+=j-r+1;
                temp[k++]=v[l++];
            }
        }
        
        while(l<mid)
            temp[k++]=v[l++];
        while(r<=j)
            temp[k++]=v[r++];
        
        for(k=0;k<n;k++)
            v[i+k]=temp[k];
    }
    
    void mergesort(vector<pair<int,int> >&v,vector<int>&ans,int i,int j)
    {
        if(i<j)
        {
            int mid=(i+j)/2;
            mergesort(v,ans,i,mid);
            mergesort(v,ans,mid+1,j);
            merge(v,ans,i,mid,j);
        }
    }
    
    vector<int> countSmaller(vector<int>& nums) {
        int n=nums.size();
        vector<pair<int,int> >v;
        vector<int>ans(n,0);
        for(int i=0;i<n;i++)
            v.push_back({nums[i],i});
        mergesort(v,ans,0,n-1);
        
        return ans;
    }
};
