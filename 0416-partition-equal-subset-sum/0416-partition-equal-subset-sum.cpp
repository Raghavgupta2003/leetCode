// class Solution {
// public:
//     bool helper(int idx, int target, vector<int>& nums, vector<vector<int>>& dp){
//         if(idx == 0) return (target == nums[idx]);
//         if(target == 0) return true;
        
//         if(dp[idx][target]!=-1) return dp[idx][target];

//         bool pick = false;
//         if(target >= nums[idx]) pick = helper(idx-1, target-nums[idx], nums,dp);

//         bool notpick = helper(idx-1, target, nums, dp);

//         return dp[idx][target] = (pick || notpick);
//     }
//     bool canPartition(vector<int>& nums) {
//         int target = 0;
//         for(int i=0; i<nums.size(); i++){
//             target+=nums[i];
//         }
//         if(target%2 == 0) target = target/2;
//         else return false;

//         //dp;
//         int n = nums.size();
//         vector<vector<int>> dp(n, vector<int> (target+1, -1));
//         return helper(n-1, target,nums, dp);
//     }
// };

//------------------Tabulation---------
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int target = 0;
        for(int i=0; i<nums.size(); i++){
            target+=nums[i];
        }
        if(target%2 == 0) target = target/2;
        else return false;

        
        int n = nums.size();
        vector<vector<bool>> dp(n, vector<bool> (target+1, 0));
        //basecase

        for(int i=0; i<nums.size(); i++){
            //when target == 0;
            dp[i][0] = true;
        }
        //if idx = 0  && target == nums[0]
        if (nums[0] <= target) {
            dp[0][nums[0]] = true;
        }


        //dp;
        for(int idx = 1; idx<n; idx++){
            for(int tar = 1; tar<=target; tar++){
                bool pick = false;
                if(tar >= nums[idx]) pick = dp[idx-1][tar-nums[idx]];

                bool notpick = dp[idx-1][tar];

                dp[idx][tar] = (pick || notpick);
            }
        }

        return dp[n-1][target];
    }
};