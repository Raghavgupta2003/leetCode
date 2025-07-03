class Solution {
public:
    int rec(int n, vector<int>& nums, vector<int>& dp){
        if(n < 0) return 0;

        if(dp[n]!=-1) return dp[n];
        int pick = nums[n] + rec(n-2, nums, dp);
        int notpick = 0 + rec(n-1, nums, dp);

        return  dp[n] = max(pick, notpick);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);

        return rec(n-1,nums, dp);
    }
};