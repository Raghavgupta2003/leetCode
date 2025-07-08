// class Solution {
// public:
//     int lcs(int n1, int n2, string s1, string s2, vector<vector<int>>& dp){
//         if(n1<0 || n2<0) return 0;
        
//         if(dp[n1][n2] != -1) return dp[n1][n2];

//         if(s1[n1] == s2[n2]) return 1+lcs(n1-1, n2-1, s1, s2, dp);

//         return dp[n1][n2] = max(lcs(n1-1, n2, s1, s2, dp), lcs(n1, n2-1, s1, s2, dp));
//     }
//     int longestPalindromeSubseq(string s) {
//         string s1 = s;
//         string s2 = s;
//         reverse(s2.begin(), s2.end());

//         int n1 = s1.size();
//         int n2 = s2.size();

//         vector<vector<int>> dp(n1, vector<int>(n2, -1));

//         return lcs(n1-1, n2-1, s1, s2, dp);
//     }
// };


//----------------------------tabulation----------------------


// class Solution {
// public:
//     int longestPalindromeSubseq(string s) {
//         string s1 = s;
//         string s2 = s;
//         reverse(s2.begin(), s2.end());

//         int n1 = s1.size();
//         int n2 = s2.size();

//         vector<vector<int>> dp(n1+1, vector<int>(n2+1, 0)); //we have taken +1 size

//         //basecase -> if(i==0 || j==0) return 0;

//         for(int i=0; i<=n1; i++){
//             dp[i][0]=0;
//         }
//         for(int j=0; j<=n2; j++){
//             dp[0][j] = 0;
//         }

//         for(int i=1; i<=n1; i++){
//             for(int j=1; j<=n2; j++){
//                 if(s1[i-1] == s2[j-1]){
//                     dp[i][j] = 1+ dp[i-1][j-1];
//                 }
//                 else{
//                     dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
//                 }
//             }
//         }

//         return dp[n1][n2];
//     }
// };


//-----------------------by single string only-------------------------

// class Solution {
// public:
//     int lcs(int n1, int n2, string s, vector<vector<int>>& dp){
//         if(n1<0 || n2>=s.size()) return 0;
    
//         if(dp[n1][n2] != -1) return dp[n1][n2];

//         if(s[n1] == s[n2]) return 1+lcs(n1-1, n2+1, s, dp);

//         return dp[n1][n2] = max(lcs(n1-1, n2, s, dp), lcs(n1, n2+1, s, dp));
//     }
//     int longestPalindromeSubseq(string s) {
//         int n = s.size();

//         vector<vector<int>> dp(n, vector<int>(n, -1));
//         int n1 = n-1;
//         int n2 = 0;
//         return lcs(n1, n2, s, dp);
//     }
// };


//-----------------by single string but we travel only half of array-------

// class Solution {
// public:
//     int lcs(int n1, int n2, string s, vector<vector<int>>& dp){
//         // base case
//         if(n1 < n2) return 0;
//         if(n1 == n2) return 1; //part of palindrome
       
        
//         if(dp[n1][n2] != -1) return dp[n1][n2];

//         if(s[n1] == s[n2]) return 2+lcs(n1-1, n2+1, s, dp);

//         return dp[n1][n2] = max(lcs(n1-1, n2, s, dp), lcs(n1, n2+1, s, dp));
//     }
//     int longestPalindromeSubseq(string s) {
//         int n = s.size();

//         vector<vector<int>> dp(n, vector<int>(n, -1));
//         int n1 = n-1;
//         int n2 = 0;
//         return lcs(n1, n2, s, dp);
//     }
// };


//----------------tabulation---------------------------

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();

        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
       
        //basecase : fill all zero for(i < j)
        //         : fill 1 at all (i==j)
        // for(int i=0; i<n; i++){
        //     for(int j=0; j<n; j++){
        //         if(i==j) dp[i][j] = 1;
        //         if(i<j) dp[i][j] = 0;
        //     }
        // }

        //llogic
        // dp.size()-2 == n-1
        for(int i=1; i<dp.size(); i++){
            for(int j=dp.size()-2; j>=0; j--){
                if(s[i-1]==s[j]){
                    dp[i][j] = 1 + dp[i-1][j+1];
                }
                else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j+1]);
                }
            }
        }

        return dp[n][0];
    }
};
