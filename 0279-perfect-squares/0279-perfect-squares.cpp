class Solution {
public:
  
    int cnt(int n,  vector<int>& arr, int target,vector<vector<int>>& dp){
        if(n == 0){
           if(target % arr[n] == 0) return target/arr[n];

           return 1e9;
        }

        if(dp[n][target]!=-1){
            return dp[n][target];
        }

        int pick = 1e9;
        if(target >= arr[n]) pick = 1 + cnt(n, arr, target-arr[n],dp);

        int notpick = cnt(n-1, arr, target,dp);

        return dp[n][target]=min(pick, notpick);
    }
    int numSquares(int n) {
        vector<int> sq;
        for(int i=1; i<=n; i++){
            int x = sqrt(i);
            if( x*x == i) sq.push_back(i);
        }
        vector<vector<int>> dp(sq.size(),vector<int>(n+1,-1));
        return cnt(sq.size()-1, sq, n,dp);

    }
};