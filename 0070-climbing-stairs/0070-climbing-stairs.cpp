// class Solution {
// public:
//     int ways(int idx){
//         if(idx == 0) return 1;
//         if(idx == 1) return 1;

//         int left = ways(idx-1);
//         int right = ways(idx-2);

//         return left + right;
//     }
//     int climbStairs(int n) {
//         return ways(n);
//     }
// };

//---------------DP----------------------

// class Solution {
// public:
//     int ways(int idx, vector<int> &dp){
//         if(idx == 0) return 1;
//         if(idx == 1) return 1;
//         if(dp[idx] != -1) return dp[idx];

//         int left = ways(idx-1, dp);
//         int right = ways(idx-2, dp);

//         return dp[idx] = left + right;
//     }
//     int climbStairs(int n) {
//         vector<int> dp(n+1, -1);
//         return ways(n,dp);
//     }
// };


//----------------------tabulation--------------------

// class Solution {
// public:
    
//     int climbStairs(int n) {
//         vector<int> dp(n+1);
//         dp[0] = 1;
//         dp[1] = 1;
//         for(int i=2; i<dp.size(); i++){
//             dp[i] = dp[i-1] + dp[i-2];
//         }
//         return dp[n];
//     }
// };


//-----------------------space optimized tabulation-----------


class Solution {
public:
    
    int climbStairs(int n) {
        vector<int> dp(n+1);
        int prev2 = 1;
        int prev = 1;
        for(int i=2; i<dp.size(); i++){
            int curi = prev2 + prev;
            prev2 = prev;
            prev = curi;
        }
        return prev;
    }
};