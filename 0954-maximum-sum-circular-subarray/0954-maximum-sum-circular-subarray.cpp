class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        //case 1: if answer is in b/w of array
        //then calculate maxsum by kadane.

        //case 2: if answer comprise of starting and ending part ->(circular part)
        // maxsum = totalSum - minimumsumSubarray.
        // 5, -3, -1, 5  -> maxsum = 10([5,5]), minimumsum = -4([-3,-1])

        //case 1:
        int maxsum = nums[0];
        int cursum = nums[0];
        for(int i=1; i<nums.size(); i++){
            cursum = max(nums[i], cursum + nums[i]);
            maxsum = max(cursum, maxsum);
        }
          
        //case 2:
        int total = 0;
        for(int i=0; i<nums.size(); i++){
            total += nums[i];
        }
        int minsum = nums[0];
        cursum = nums[0];
        for(int i=1; i<nums.size(); i++){
            cursum = min(nums[i], cursum + nums[i]);
            minsum = min(cursum, minsum);
        }
        int cir_maxsum = total - minsum;
        if(cir_maxsum == 0) return maxsum;
        //max(case1, case2);

        return max(maxsum, cir_maxsum);

    }
};