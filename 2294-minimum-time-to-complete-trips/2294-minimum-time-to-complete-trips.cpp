class Solution {
public:
    bool canBedoneAtleastTrips(long long sec, vector<int>&time, int totalTrips){
        long long trips = 0;
        for(int i=0; i<time.size(); i++){
            trips += sec/time[i];
        }

        return trips >= totalTrips;
    }
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long low = 1;
        long long high = (long long)*min_element(time.begin(), time.end()) * totalTrips;//it means only bus0 travel k times and other buses do not run

        long long ans = -1;

        while(low <= high){
            long long mid = low + (high-low)/2;

            if(canBedoneAtleastTrips(mid, time, totalTrips)){
                ans = mid; //it can be ans
                high = mid - 1;
            }else{
                low = mid+1;
            }
        }
        return ans;
    }
};