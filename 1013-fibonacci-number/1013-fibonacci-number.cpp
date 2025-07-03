class Solution {
public:
    // int f(int n, vector<int>& dp) {
    //     if(n == 0 || n==1) return n;

    //     if(dp[n]!=-1) return dp[n]; 
    //     return dp[n] = f(n-1, dp) + f(n-2, dp);
    // }
    // int fib(int n) {
    //    vector<int> dp(n+1, -1);

    //    return f(n, dp);
    // }

    // //-----------------TABULATION---------------

    // int fib(int n) {
    //    vector<int> dp(n+1, -1);

    //    if(n==0) return 0;
       
        
    //    dp[0] = 0;
    //    dp[1] = 1;
    //    for(int i=2; i<dp.size(); i++){
    //     dp[i] = dp[i-1] + dp[i-2];
    //    }
    //    return dp[n];
    // }

    //--------SPACE OPTIMIZATION---------------

    int fib(int n) {
       vector<int> dp(n+1, -1);

       if(n==0) return 0;
       
        
       int prev = 0;
       int cur = 1;
       for(int i=2; i<dp.size(); i++){
         int temp =  prev  + cur;
         prev = cur;
         cur = temp;
       }
       return cur;
    }
};