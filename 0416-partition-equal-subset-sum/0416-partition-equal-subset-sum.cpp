class Solution {
public:
    bool helper(int idx, int target, vector<int>& nums, vector<vector<int>>& dp){
        if(idx < 0) return false;
        if(idx == 0) return nums[idx] == target;

        if(dp[idx][target] != -1) return dp[idx][target];
        bool pick = false;
        if(target >= nums[idx]) pick = helper(idx-1, target-nums[idx], nums, dp);

        bool notpick = helper(idx-1, target, nums, dp);

        return dp[idx][target] = pick||notpick;
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int i=0; i<n; i++){
            sum+=nums[i];
        }
        if(sum%2 != 0) return false; //cannot converted into 2
        int target = sum/2;
        vector<vector<int>> dp(n, vector<int>(target+1, -1));
        return helper(n-1, target, nums, dp);
    }
};