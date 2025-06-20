class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {

        //----BRUTE FORCE with TLE--------
        // int speed = 1;
        // while(true){
        //     int hours = 0;
            
        //     for(int i=0; i<piles.size(); i++){
        //         hours += ceil((double)piles[i]/speed);
        //     }

        //     if(hours == h) return speed;
        //     speed++;
        // }
        // return 0;

        //----------BINARY SEARCH----------

        long long low = 1;
        long long high = *max_element(piles.begin(), piles.end());
        long long ans = -1;
        while(low<=high){
            long long mid = low + (high-low)/2; //speed

            long long hours = 0;
            for(int i=0; i<piles.size(); i++){
                hours += ceil((double)piles[i]/mid);
            }

            if(hours <= h){
                //try less speed
                ans = mid;
                high = mid-1;
            }
            else if(hours > h){
                //try more speed
                low = mid+1;
            }
        }
        return ans;
    }
};