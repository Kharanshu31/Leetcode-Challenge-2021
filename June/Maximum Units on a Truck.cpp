class Solution {
public:
    
    static bool cmp(const vector<int>&a,const vector<int>&b)
    {
        if(a[1]==b[1])
            return a[0]>b[0];
        return a[1]>b[1];
    }
    
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(),boxTypes.end(),cmp);
        int ans=0;
        int n=boxTypes.size();
        for(int i=0;i<n;i++)
        {
            cout<<boxTypes[i][0]<<"  "<<boxTypes[i][1]<<"\n";
            if(truckSize>boxTypes[i][0])
            {
                ans+=boxTypes[i][0]*boxTypes[i][1];
                truckSize-=boxTypes[i][0];
            }
            else
            {
                ans+=truckSize*boxTypes[i][1];
                break;
            }
        }
        return ans;
    }
};
