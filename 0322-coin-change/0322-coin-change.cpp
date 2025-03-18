class Solution {
public:
    int helper(int idx, vector<int>& coins, int amount, vector<vector<int>>& dp){
        if(idx == 0){
            // What if  x coins of denomination of coins[0] are used to make coins.
            if(amount % coins[idx] == 0) return amount/coins[idx];
            return 1e9;
        }

        if(dp[idx][amount] != -1)  return dp[idx][amount];

        int pick = INT_MAX;
        if(amount >= coins[idx]) pick = 1 + helper(idx, coins, amount-coins[idx], dp);

        int notpick = 0 + helper(idx-1, coins, amount, dp);

        return dp[idx][amount] = min(pick, notpick);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int> (amount+1, -1));
        if(helper(n-1, coins, amount, dp) == 1e9) return -1;
        else 
        return helper(n-1, coins, amount, dp);
    }
};