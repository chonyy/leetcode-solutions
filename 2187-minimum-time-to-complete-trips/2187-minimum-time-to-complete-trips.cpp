class Solution {
public:
    bool enoughTime(long long curTime, vector<int>& time, int totalTrips) {
        long long trips = 0;
        
        for(auto t : time) {
            trips += curTime / (long long)t;
        }
        
        return trips >= totalTrips;
    }
    
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long l = 0;
        long long r = 1e14;
        
        while(l < r) {
            long long mid = l + (r-l) / 2;
            if(enoughTime(mid, time, totalTrips)) {
                r = mid;
            }
            else {
                l = mid + 1;
            }
        }
        
        return l;
    }
};