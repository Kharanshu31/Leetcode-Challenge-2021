class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int n=heights.size();
        int i=0;
        priority_queue<int>pq;
        int sum=0;
        for(i=0;i<n-1;i++)
        {
            if(heights[i+1]<heights[i])
                continue;
            pq.push(heights[i+1]-heights[i]);
            sum+=heights[i+1]-heights[i];
            cout<<" sum : "<<sum<<" lad : "<<ladders<<" i : "<<i<<"\n";
            if(sum>bricks)
            {
                if(ladders>0)
                {
                    while(!pq.empty() && sum>bricks && ladders>0)
                    {
                        sum-=pq.top();
                        ladders--;
                        pq.pop();
                    }
                }
                else
                {
                    break;
                }
            }
        }
        return i;
    }
};
