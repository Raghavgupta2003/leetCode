class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        // tabulation for longest common subsequence

        int n1 = str1.size();
        int n2 = str2.size();
        vector<vector<int>> dp(n1+1, vector<int>(n2+1, 0));

        //basecase
        for(int i=0; i<=n1; i++){
            dp[i][0] = 0;
        }
        for(int j=0; j<=n2; j++){
            dp[0][j] = 0;
        }

        //dp
        for(int i=1; i<=n1; i++){
            for(int j=1; j<=n2; j++){
                if(str1[i-1] == str2[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        // cout<<dp[n1][n2];

        // printing lcs with minor changes
        string str = "";
        int i=n1;
        int j=n2;
        while(i>0 && j>0){
            if(str1[i-1] == str2[j-1]){
                str += str1[i-1];
                i--;
                j--;
            }else if(dp[i-1][j] > dp[i][j-1]){
                str+=str1[i-1]; // changes in printing lcs
                i--;
            }else{
                str+=str2[j-1];  // changes in printing lcs
                j--;
            }
        }
        // remaining str1
        while(i>0){
            str+=str1[i-1];
            i--;
        }
        //remaining str2
        while(j>0){
            str+=str2[j-1]; // we use j-1 as initially j=str2.size(), because of this we cant fetch (lastindex + 1)th element
            j--;
        }
        
        reverse(str.begin(), str.end());
        return str;
    }
};