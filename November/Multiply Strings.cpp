class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1=="0" || num2=="0")
            return "0";
        
        vector<int>ar(num1.length()+num2.length(),0);
        for(int i=num1.length()-1;i>=0;i--)
        {
            for(int j=num2.length()-1;j>=0;j--)
            {
                ar[i+j+1]+=(num1[i]-'0')*(num2[i]-'0');
                ar[i+j]+=ar[i+j+1]/10;
                ar[i+j+1]%=10;
            }
        }
        
        int i=0;
        while(i<ar.size() && ar[i]==0)
            i++;
        
        string ans="";
        for(int k=i;k<ar.size();k++)
            ans+=(ar[k]+'0');
        return ans;
    }
};
