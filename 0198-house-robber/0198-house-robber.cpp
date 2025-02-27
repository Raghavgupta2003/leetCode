// class Solution {
// public:
//     int helper(int idx, vector<int> &nums){
//         if(idx>=nums.size()) return 0;
//         //pick 
        
//         int left = nums[idx] + helper(idx+2, nums);
//         //not pick
//         int right = 0 + helper(idx + 1, nums);

//         return max(left,right);
//     }
//     int rob(vector<int>& nums) {
//         return helper(0, nums);
//     }
// };

//---------------Memorization-------------------


// class Solution {
// public:
//     int helper(int idx, vector<int> &nums, vector<int> &dp){
//         if(idx>=nums.size()) return 0;

//         if(dp[idx]!=-1) return dp[idx];
//         //pick 
//         int left = nums[idx] + helper(idx+2, nums,dp);
//         //not pick
//         int right = 0 + helper(idx + 1, nums,dp);

//         return dp[idx] = max(left,right);
//     }
//     int rob(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> dp(n,-1);
//         return helper(0, nums,dp);
//     }
// };

//---------------Tabulation-------------------


class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,-1);

        dp[0] = nums[0];
        if(nums.size() > 1) dp[1] =  max(nums[0],nums[1]);
        
        for(int i=2; i<dp.size(); i++){
            //pick
            int left = nums[i] + dp[i-2];
            //not pick
            int right = dp[i-1];

            dp[i] = max(left,right);
        }

        return dp[n-1];
    }
};