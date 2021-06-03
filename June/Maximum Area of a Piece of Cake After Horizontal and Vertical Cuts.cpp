class Solution {
public:
    int maxArea(int h, int w, vector<int>& hr, vector<int>& vr) {
        sort(hr.begin(),hr.end());
        sort(vr.begin(),vr.end());
        int n=hr.size();
        int m=vr.size();
        int mxh=max(hr[0],h-hr[n-1]);
        int mxv=max(vr[0],w-vr[m-1]);
        for(int i=0;i<n-1;i++)   
            mxh=max(mxh,hr[i+1]-hr[i]);
        for(int i=0;i<m-1;i++)   
            mxv=max(mxv,vr[i+1]-vr[i]);
        
        long long ans=(long long)(mxh)*(long long)(mxv);
        ans%=1000000007;
        return ans;
    }
};
