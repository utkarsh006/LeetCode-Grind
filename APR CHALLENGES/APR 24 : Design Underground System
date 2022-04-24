class UndergroundSystem {
public:
    unordered_map<string, pair<int, int>> checkoutMap; // Route - {TotalTime, Count}
    unordered_map<int, pair<string, int>> checkInMap; // Uid - {StationName, Time}
    
    UndergroundSystem() {}
    
    void checkIn(int id, string stationName, int t) {
        checkInMap[id] = {stationName, t};
    }
    
    void checkOut(int id, string stationName, int t) {
        auto& checkIn = checkInMap[id];
        string route = checkIn.first + "_" + stationName;
        checkoutMap[route].first += t - checkIn.second;
        checkoutMap[route].second += 1;
    }
    
    double getAverageTime(string startStation, string endStation) {
        string route = startStation + "_" + endStation;
        auto& checkout = checkoutMap[route];
        return (double) checkout.first / checkout.second;
    }
};
