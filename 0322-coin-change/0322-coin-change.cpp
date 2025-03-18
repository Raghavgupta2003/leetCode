// class Solution {
// public:
//     int helper(int idx, vector<int>& coins, int amount, vector<vector<int>>& dp){
//         if(idx == 0){
//             // What if  x coins of denomination of coins[0] are used to make coins.
//             if(amount % coins[idx] == 0) return amount/coins[idx];
//             return 1e9;
//         }

//         if(dp[idx][amount] != -1)  return dp[idx][amount];

//         int pick = INT_MAX;
//         if(amount >= coins[idx]) pick = 1 + helper(idx, coins, amount-coins[idx], dp);

//         int notpick = 0 + helper(idx-1, coins, amount, dp);

//         return dp[idx][amount] = min(pick, notpick);
//     }
//     int coinChange(vector<int>& coins, int amount) {
//         int n = coins.size();
//         vector<vector<int>> dp(n, vector<int> (amount+1, -1));
//         if(helper(n-1, coins, amount, dp) == 1e9) return -1;
//         else 
//         return helper(n-1, coins, amount, dp);
//     }
// };


//----------------------------------Tabulation---------------------------



class Solution {
public:
    int coinChange(vector<int>& coins, int at) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int> (at+1, 1e9));

        //baseCase
        for(int i=0; i<= at; i++){
            if(i % coins[0] == 0){
                dp[0][i] = i/coins[0];
            }
        }

        //dp
        for(int idx=1; idx<n; idx++){
            for(int amount=0; amount<=at; amount++){
                int pick = INT_MAX;
                if(amount >= coins[idx]) pick = 1 + dp[idx][amount-coins[idx]];

                int notpick = 0 + dp[idx-1][amount];

                dp[idx][amount] = min(pick, notpick);
            }
        }

        if (dp[n-1][at] == 1e9) return -1;
        else 
        return dp[n-1][at];
    }
};