class UndergroundSystem {
public:
    unordered_map<int,pair<string,int>>checkinInfo;
    unordered_map<string,pair<int,int>>travelData;


    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        checkinInfo[id]={stationName,t};//storing the station name and chckin time
    }
    
    void checkOut(int id, string stationName, int t) {
        auto [station,time] = checkinInfo[id];
        checkinInfo.erase(id);
        string routr = station+"_"+stationName;
        int triptime = t-time;
        travelData[routr].first+=triptime;
        travelData[routr].second+=1;
    }
    
    double getAverageTime(string startStation, string endStation) {
        string route = startStation+"_"+endStation;
        auto [totaltime,count]= travelData[route];
        return (double)totaltime/count;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */