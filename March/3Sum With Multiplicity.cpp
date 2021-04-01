class Solution {
public:
    const int mod=1e9+7;
    int threeSumMulti(vector<int>& ar, int target) {
        int n=ar.size();
        unordered_map<int,long>m;
        for(auto it:ar)
            m[it]++;
        
        long ans=0;
        for(auto it1:m)
        {
            for(auto it2:m)
            {
                int a=it1.first;
                int b=it2.first;
                if(!m.count(target-a-b))
                    continue;
                if(a==b && a==target-a-b)
                {
                    cout<<" a : "<<a<<" b : "<<b<<" t : "<<target-a-b<<"\n";
                    ans+=(m[a]*(m[a]-1)*(m[a]-2))/6;
                }
                else if(a==b)
                {
                    cout<<" a : "<<a<<" b : "<<b<<" t : "<<target-a-b<<"\n";
                    ans+=((m[a]*(m[a]-1))/2)*m[target-a-b];
                }
                else if(a<b && b<target-a-b)
                {
                    cout<<" a : "<<a<<" b : "<<b<<" t : "<<target-a-b<<"\n";
                    ans+=m[a]*m[b]*m[target-a-b];
                }
                ans%=mod;
            }
            ans%=mod;
        }
        ans%=mod;
        return ans;
    }
};
