class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        // we cannot ignore negative
        // we find max subarray sum
        // we find min subarray sum
        // and return maximum of both of them
        

        //--------maxsum -> kadane's algorithm -----------
        int cursum = nums[0];
        int maxsum = nums[0];
        for(int i=1; i<nums.size(); i++){
            cursum = max(nums[i] ,cursum + nums[i]);
            maxsum = max(maxsum, cursum);
        }

        //--------minsum-------------

        cursum = nums[0];
        int minsum = nums[0];
        for(int i=1; i<nums.size(); i++){
            cursum = min(nums[i] ,cursum+nums[i]);
            minsum = min(minsum, cursum);
        }

        return max(abs(maxsum), abs(minsum));
        
    }
};