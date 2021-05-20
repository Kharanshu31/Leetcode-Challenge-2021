class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        vector<vector<string> >ans;
        unordered_map<string,vector<string> >m;
        for(auto s:paths)
        {
            int i=0,n=s.length();
            string pt="";
            while(i<n && s[i]!=' ')
                pt+=s[i++];
            pt+='/';
            ++i;
            while(i<n)
            {
                string temp="",file="";
                while(i<n && s[i]!='(')
                    temp+=s[i++];
                while(i<n && s[i]!=' ')
                    file+=s[i++];
                m[file].push_back(pt+temp);
                ++i;
            }
        }
        
        for(auto it:m)
        {
            if(it.second.size()>1)
                ans.push_back(it.second);
        }
        
        return ans;
    }
};
