class Solution {
public:
    int op(int i, int j, string s1, string s2,  vector<vector<int>>& dp){
        if(j == s2.size()) return s1.size() - i; //delete reamaining from s1, to make s1 = s2
        if(i == s1.size()) return s2.size()-j;
        
        if(dp[i][j] != -1) return dp[i][j];
        if(s1[i] != s2[j]){

            //Insert a char
            int insert = 1 + op(i, j+1, s1, s2, dp);

            //delete a char
            int del = 1 + op(i+1, j, s1, s2, dp);

            //replace
            int replace = 1 + op(i+1, j+1, s1, s2, dp);

            return dp[i][j] = min(insert, min(del, replace));
        }
        else{
            // s1[i]==s2[i] => means no operation
            return dp[i][j] = op(i+1, j+1, s1, s2, dp);
        }
    }
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        vector<vector<int>> dp(m, vector<int>(n, -1));

        return op(0, 0, word1, word2, dp);
    }
};