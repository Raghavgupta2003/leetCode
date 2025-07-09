// class Solution {
// public:
//     int op(int i, int j, string s1, string s2,  vector<vector<int>>& dp){
//         if(j == s2.size()) return s1.size() - i; //delete reamaining from s1, to make s1 = s2
//         if(i == s1.size()) return s2.size()-j;
        
//         if(dp[i][j] != -1) return dp[i][j];
//         if(s1[i] != s2[j]){

//             //Insert a char
//             int insert = 1 + op(i, j+1, s1, s2, dp);

//             //delete a char
//             int del = 1 + op(i+1, j, s1, s2, dp);

//             //replace
//             int replace = 1 + op(i+1, j+1, s1, s2, dp);

//             return dp[i][j] = min(insert, min(del, replace));
//         }
//         else{
//             // s1[i]==s2[i] => means no operation
//             return dp[i][j] = op(i+1, j+1, s1, s2, dp);
//         }
//     }
//     int minDistance(string word1, string word2) {
//         int m = word1.size();
//         int n = word2.size();
//         vector<vector<int>> dp(m, vector<int>(n, -1));

//         return op(0, 0, word1, word2, dp);
//     }
// };


//-------------------------------------------------------------------


// class Solution {
// public:
//     int op(int i, int j, string s1, string s2,  vector<vector<int>>& dp){
//         if(j < 0) return i+1; //delete reamaining from s1, to make s1 = s2
//         if(i < 0) return j+1;
        
//         if(dp[i][j] != -1) return dp[i][j];

//         if(s1[i] != s2[j]){

//             //Insert a char
//             int insert = 1 + op(i, j-1, s1, s2, dp);

//             //delete a char
//             int del = 1 + op(i-1, j, s1, s2, dp);

//             //replace
//             int replace = 1 + op(i-1, j-1, s1, s2, dp);

//             return dp[i][j] = min(insert, min(del, replace));
//         }
//         else{
//             // s1[i]==s2[i] => means no operation
//             return dp[i][j] = op(i-1, j-1, s1, s2, dp);
//         }
//     }
//     int minDistance(string word1, string word2) {
//         int m = word1.size();
//         int n = word2.size();
//         vector<vector<int>> dp(m, vector<int>(n, -1));

//         return op(m-1, n-1, word1, word2, dp);
//     }
// };

//--------------------------TABULATION--------------------------


class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, 1e9));

        //basecase
        for(int i=0; i<=m; i++){
            dp[i][0] = i;  // here we do not + 1 as we are considering 0 as less than 0
        }
        for(int j=0; j<=n; j++){
            dp[0][j] = j;
        }

        //logic

        for(int i=1; i<=m; i++){
            for(int j=1; j<=n; j++){
                if(word1[i-1] != word2[j-1]){
                    //Insert a char
                    int insert = 1 + dp[i][j-1];

                    //delete a char
                    int del = 1 + dp[i-1][j];

                    //replace
                    int replace = 1 + dp[i-1][j-1];

                    dp[i][j] = min(insert, min(del, replace));
                }else{
                    dp[i][j] = dp[i-1][j-1];
                }
            }
        }
        return dp[m][n];
    }
};