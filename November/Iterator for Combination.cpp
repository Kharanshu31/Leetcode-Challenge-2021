class CombinationIterator {
public:
    vector<string>ar;
    int cur=0;
    CombinationIterator(string characters, int combinationLength) {
        int n=combinationLength;
        for(int i=1;i<=pow(2,characters.length());i++)
        {
            string temp="";
            for(int j=0;j<characters.length();j++)
            {
                if(i & 1<<j)
                    temp+=characters[j];
            }
            if(temp.length()==n)
                ar.push_back(temp);
        }
        
        sort(ar.begin(),ar.end());
        
    }
    
    string next() {
        return ar[cur++];
    }
    
    bool hasNext() {
        return cur!=ar.size();
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
