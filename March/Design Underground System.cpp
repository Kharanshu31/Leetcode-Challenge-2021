class UndergroundSystem {
public:
    unordered_map<int,pair<string,int>>p;
    unordered_map<string,pair<int,int>>s;
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        p[id]={stationName,t};   
    }
    
    void checkOut(int id, string stationName, int t) {
        pair<string,int>f=p[id];
        string station=f.first;
        station+=" ";
        station+=stationName;
        if(s.find(station)!=s.end())
        {
            pair<int,int>a=s[station];
            a.first+=t-f.second;
            a.second++;
            s[station]=a;
        }
        else
        {
            s[station]={t-f.second,1};
        }
    }
    
    double getAverageTime(string startStation, string endStation) {
        double ans=0.0;
        string station=startStation;
        station+=" ";
        station+=endStation;
        if(s.find(station)!=s.end())
        {
            pair<int,int>a=s[station];
            ans=(double)(a.first)/(double)(a.second);
        }
        return ans;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */
