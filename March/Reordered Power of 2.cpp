class Solution {
public:
    bool reorderedPowerOf2(int N) {
        set<long>s;
        vector<vector<string>>digit(12);
        long ct=1;
        while(ct<=1e9)
        {
            string st=to_string(ct);
            int n=st.length();
            digit[n].push_back(st);
            ct*=2;
        }
        
        string num=to_string(N);
        cout<<num<<"\n";
        sort(num.begin(),num.end());
        for(auto it:digit[num.length()])
        {
            cout<<" it : "<<it<<"\n";
            sort(it.begin(),it.end());
            if(it==num)
                return true;
        }
        return false;
    }
};
