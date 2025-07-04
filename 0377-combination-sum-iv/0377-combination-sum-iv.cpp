class Solution {
public:   
    //  int sum(vector<int>& nums, int target,  vector<int>& dp){
    //     if(target == 0) return 1;
    //     if(target < 0) return 0;

    //     if(dp[target] != -1) return dp[target];

    //     int count = 0;
    //     for(int i=0; i<nums.size(); i++){
    //         count += sum(nums, target-nums[i], dp);
    //     }
    //     return dp[target] = count;
    // }
    // int combinationSum4(vector<int>& nums, int target) {
    //     int n = nums.size();
    //     vector<int> dp(target+1, -1);
    //     return sum(nums, target, dp);
        
    // }


    int combinationSum4(vector<int>& nums, int target) {
        int n = nums.size();
        vector<unsigned int> dp(target+1, 0);
        int MOD = 1e9 + 7;
        dp[0] = 1; 
        for(int tar=1; tar<dp.size(); tar++){
            int cnt = 0;
            for(int i=0; i<nums.size(); i++){
                if(tar >= nums[i]){
                    dp[tar] += dp[tar-nums[i]];
                }
            }
        }
        return dp[target];
    }
};