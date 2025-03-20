class Solution {
public:
    int helper(int idx1, int idx2, string s1, string s2, vector<vector<int>>& dp){
        if(idx1<0 || idx2<0) return 0;
        
        if(dp[idx1][idx2] != -1) return dp[idx1][idx2];

        if(s1[idx1] == s2[idx2]) return dp[idx1][idx2] =  1 + helper(idx1-1, idx2-1, s1, s2, dp);
        
        return dp[idx1][idx2] = 0 + max(helper(idx1-1, idx2, s1, s2, dp), helper(idx1, idx2-1, s1, s2, dp));
    }
    int minDistance(string s1, string s2) {
      
        int n1 = s1.size();
        int n2 = s2.size();
        vector<vector<int>> dp(n1, vector<int> (n2, -1));

        int lcsLength = helper(n1-1, n2-1, s1, s2, dp);

        return (s1.size()-lcsLength) + (s2.size()-lcsLength);
    }
};
