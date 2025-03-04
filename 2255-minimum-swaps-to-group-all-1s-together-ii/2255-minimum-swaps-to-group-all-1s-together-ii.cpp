class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        int windowSize = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] == 1) windowSize++;
        }

        //basecase
        if (windowSize == 0 || windowSize == nums.size()) return 0;

        // Extend the array circularly
        for(int i=0; i<n; i++){
            nums.push_back(nums[i]);
        }

        int i=0;
         
        int minSwapNumber = INT_MAX;
        int SwapNumber = 0;
        for(int j=0; j<nums.size(); j++){
            if(nums[j] == 0){
                SwapNumber++;
            }
            if(j - i + 1 == windowSize){
                minSwapNumber = min(minSwapNumber, SwapNumber);
                if(nums[i]==0) SwapNumber--;
                i++;
            }
        }
        return minSwapNumber;
    }
};