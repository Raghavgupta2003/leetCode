class Solution {
public:
    bool help(int n, int target, vector<int>& nums, vector<vector<int>>& dp){
        // if(n<0){
        //     if(target == 0) return true;
        //     return false;
        // }
        
        if(target == 0) return true;
        if(n == 0) return nums[0] == target;


        if(dp[n][target] != -1) return  dp[n][target];

        bool pick = false;
        if(target >= nums[n]) pick =  help(n-1, target-nums[n], nums, dp);

        bool notpick = help(n-1, target, nums, dp);

        return dp[n][target] = pick || notpick;
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int i=0; i<nums.size(); i++){
            sum += nums[i];
        }

        if(sum % 2 != 0) return false;

        int target = sum/2;
        vector<vector<int>> dp(n, vector<int>(target+1, -1));

        return help(n-1, target, nums, dp);
    }
};