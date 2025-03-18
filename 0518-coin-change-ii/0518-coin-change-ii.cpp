class Solution {
public:
    int helper(int idx, int amount, vector<int>& coins, vector<vector<int>>& dp){
        // if(amount == 0) return 1;
        // if(idx<0) return 0;

        if(idx == 0){
            return (amount % coins[0] == 0);
        }

         if(dp[idx][amount] != -1)  return dp[idx][amount];

        int pick = 0;
        if(amount >= coins[idx]) pick = helper(idx, amount-coins[idx], coins, dp);

        int notpick = helper(idx-1, amount, coins, dp);

        return dp[idx][amount] = pick + notpick;

    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int> (amount+1, -1));

        return helper(n-1, amount, coins, dp);
    }
};