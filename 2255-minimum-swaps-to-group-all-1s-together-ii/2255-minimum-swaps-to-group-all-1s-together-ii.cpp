class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        //for circular subarray, we append nums to nums
        for(int i=0; i<n; i++){
            nums.push_back(nums[i]);
        }

        //Now we calculate the subarrays of with minimum zero
        //window size = number of ones ***in original array***

        int windowsize = 0;

        for(int i=0; i<nums.size()/2; i++){ //since we appended the one other array too.
            if(nums[i]==1) windowsize++;
        }
        if(windowsize == 0) return 0;

        //sliding window with fixwed size

        n = nums.size();
        int i=0;
        int j=0;
        int cnt0 = 0;
        int minZero = INT_MAX; //minimum Swaps

        while(i<n){
            if(nums[i] == 0) cnt0++;

            int window = i-j+1;

            if(window == windowsize){
                minZero = min(minZero, cnt0);
                if(nums[j] == 0) cnt0--;
                i++;
                j++;
            }
            else i++;
        }

        return minZero;
    }
};