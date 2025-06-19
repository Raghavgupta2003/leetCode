class Solution {
public:
    bool canEatWithinTime(long speed, vector<int> piles, int h){
        long hours = 0;
        for(int i=0; i<piles.size(); i++){
            hours += ceil((double)piles[i]/speed); //to get uppper value we use ceil
        }

        if(hours <= h) return true;
        return false;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        sort(piles.begin(), piles.end());

        int low = 1;
        int high = *max_element(piles.begin(), piles.end());
        int ans = -1;
        while(low <= high){
            long mid = low + (high-low)/2;
            if(canEatWithinTime(mid, piles, h)){
                ans = mid;
                high = mid-1;
            }else{
                //we increase speed
                low = mid+1;
            }
        }


        return ans;
    }
};