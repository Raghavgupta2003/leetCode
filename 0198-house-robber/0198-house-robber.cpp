class Solution {
public:
    // int rec(int n, vector<int>& nums, vector<int>& dp){
    //     if(n < 0) return 0;

    //     if(dp[n]!=-1) return dp[n];
    //     int pick = nums[n] + rec(n-2, nums, dp);
    //     int notpick = 0 + rec(n-1, nums, dp);

    //     return  dp[n] = max(pick, notpick);
    // }
    // int rob(vector<int>& nums) {
    //     int n = nums.size();
    //     vector<int> dp(n, -1);

    //     return rec(n-1,nums, dp);
    // }

    //--------------------------------------------------

    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);

        dp[0] = nums[0];
        if(nums.size() > 1) dp[1] = max(nums[0], nums[1]);
        for(int i=2; i<n; i++){
            int pick = nums[i] + dp[i-2];
            int notpick = 0 + dp[i-1];

            dp[i] = max(pick, notpick);
        }

        return dp[n-1];
    }
};