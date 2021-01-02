class Solution {
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        int i=0;
        while(i<arr.size())
        {
            int a=arr[i];
            int pos=-1;
            for(int j=0;j<pieces.size();j++)
            {
                if(a==pieces[j][0])
                {
                    pos=j;
                    break;
                }
            }
            //cout<<" pos : "<<pos<<"\n";
            if(pos==-1)
                return false;
            bool ans=true;
            for(int j=0;j<pieces[pos].size();j++)
            {
                if(arr[i]==pieces[pos][j])
                {
                    i++;
                }
                else
                {
                    ans=false;
                    break;
                }
            }
            //cout<<" i : "<<i<<"\n";
            if(!ans)
                return false;
        }
        
        return true;
    }
};
