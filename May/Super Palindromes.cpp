typedef unsigned long long ll;
class Solution {
public:
    ll ans=0,l=0,r=0;
    bool pal(string s)
    {
        string t=s;
        reverse(t.begin(),t.end());
        return t==s;
    }
    
    void check(string s)
    {
        ll x=stoll(s);
        //if(x>r)
        //    return;
        x*=x;
        if(x>=l && x<=r && pal(to_string(x)))
        {
            cout<<x<<"\n";
            ans++;
        }
        
    }
    
    int superpalindromesInRange(string left, string right) {
        l=stoll(left);
        r=stoll(right);
        for(ll i=0;i<10000;i++)
        {
            string s=to_string(i);
            if(i<10)
                check(s);
            string t=s;
            reverse(t.begin(),t.end());
            string f=s+t;
            check(f);
            for(ll j=0;j<=9;j++)
            {
                string temp=s;
                temp+=to_string(j);
                temp+=t;
                check(temp);
            }
        }
        return ans;
    }
};
