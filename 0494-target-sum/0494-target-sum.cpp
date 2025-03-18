class Solution {
public:
    int helper(int idx, int target, vector<int>& nums, vector<vector<int>>& dp){
        if(target == 0 && idx<0) return 1;
        if(idx<0) return 0;
       
        if(dp[idx][target] != -1) return dp[idx][target];

        int pick = 0;
        if(target >= nums[idx]) pick = helper(idx-1, target-nums[idx], nums, dp);

        int notpick = helper(idx-1, target, nums, dp);

        return dp[idx][target] = pick + notpick;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int total = 0;
        for(int i=0; i<nums.size(); i++){
            total += nums[i];
        }
        if((total - target)%2 != 0) return 0;
        
        target = (total - target)/2;

        if (target < 0 || target > total) return 0; //gpt

        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(target+1, -1));

        return helper(n-1, target, nums, dp);
    }
};