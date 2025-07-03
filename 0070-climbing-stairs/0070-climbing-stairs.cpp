class Solution {
public:
    // int climb(int n,  vector<int>& dp){
    //     if(n==0 || n==1) return 1;
    //     if(dp[n] != -1) return dp[n];
    //     return dp[n] = climb(n-1, dp) + climb(n-2, dp);
    // }
    // int climbStairs(int n) {
    //     vector<int> dp(n+1, -1);
    //     return climb(n, dp);
    // }


    //-----------------------------------

    // int climbStairs(int n) {
    //     vector<int> dp(n+1, -1);

    //     dp[0] = 1;
    //     dp[1] = 1;
    //     for(int i=2; i<dp.size(); i++){
    //         dp[i] = dp[i-1]+dp[i-2];
    //     }
    //     return dp[n];
    // }

    //-------------------------------------------

    int climbStairs(int n) {
        vector<int> dp(n+1, -1);

        int prev = 1;
        int curr = 1;
        for(int i=2; i<dp.size(); i++){
            int temp = prev+curr;
            prev = curr;
            curr = temp;
        }
        return curr;
    }
};