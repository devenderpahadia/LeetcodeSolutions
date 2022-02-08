class UndergroundSystem {
public:
    
    map<int,pair<string,int>>mp;
    map<pair<string,string>,vector<int>>lp;
    
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        mp[id] = {stationName,t};
    }
    
    void checkOut(int id, string stationName, int t) {
        string str = mp[id].first;
        int start = mp[id].second;
        
        lp[{str,stationName}].push_back(t-start);
    }
    
    double getAverageTime(string startStation, string endStation) {
        
        double n = lp[{startStation,endStation}].size();
        double sum = 0;
        vector<int>res = lp[{startStation,endStation}];
        for(auto it : res)
            sum+=it;
        
        return sum/n;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */