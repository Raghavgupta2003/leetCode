// class Solution {
// public:
//     int lcs(int n1, int n2, vector<int>& nums1, vector<int>& nums2, vector<vector<int>> &dp){
//         if(n1 < 0 || n2 < 0) return 0; //anyone index out of bound

//         if(dp[n1][n2] != -1) return dp[n1][n2];

//         if(nums1[n1] == nums2[n2]) return 1+lcs(n1-1, n2-1, nums1, nums2, dp);

//         return dp[n1][n2] = max(lcs(n1-1, n2, nums1, nums2, dp), lcs(n1, n2-1, nums1, nums2, dp));
//     }
//     int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
//         int n1 = nums1.size();
//         int n2 = nums2.size();

//         vector<vector<int>> dp(n1, vector<int>(n2, -1));
//         return lcs(n1-1, n2-1, nums1, nums2, dp);
//     }
// };

//-------------------------------------------------------------------------------

// class Solution {
// public:
//     int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
//         int n1 = nums1.size();
//         int n2 = nums2.size();

//         vector<vector<int>> dp(n1+1, vector<int>(n2+1, 0));
//         //basecase
//         // when i=0 or j=0 then return 0

//         // for(int j=0; j<=n2; j++){
//         //     dp[0][j] = 0;
//         // }

//         // for(int i=0; i<=n1; i++){
//         //     dp[i][0] = 0;
//         // }

//         for(int i=1; i<=n1; i++){
//             for(int j=1; j<=n2; j++){
//                 if(nums1[i-1]==nums2[j-1]){
//                     dp[i][j] = 1+dp[i-1][j-1];
//                 } 
//                 else{
//                     dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
//                 }
//             }
//         }
//         return dp[n1][n2];
//     }
// };


//-------------------Iteration from start---------------------------------


class Solution {
public:

    //  int lcs(int i, int j, vector<int>& nums1, vector<int>& nums2, vector<vector<int>> &dp){
    //     if(i >= nums1.size() || j >= nums2.size()) return 0; //anyone index out of bound

    //     if(dp[i][j] != -1) return dp[i][j];

    //     if(nums1[i] == nums2[j]) return 1+lcs(i+1, j+1, nums1, nums2, dp);

    //     return dp[i][j] = max(lcs(i+1, j, nums1, nums2, dp), lcs(i, j+1, nums1, nums2, dp));
    // }
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        // vector<vector<int>> dp(n1, vector<int>(n2, -1));
        // return lcs(0, 0, nums1, nums2, dp);
        

        //---tabulation---

         vector<vector<int>> dp(n1+1, vector<int>(n2+1, 0));
         //at n1 and n2 index we store 0, so, loop is from idx-1 to 0
         for(int i=n1-1; i>=0; i--){
            for(int j=n2-1; j>=0; j--){
                if(nums1[i] == nums2[j]){ //here origibal indexex compared
                    dp[i][j] = 1 + dp[i+1][j+1];
                }
                else{
                    dp[i][j] = max(dp[i+1][j], dp[i][j+1]);
                }
            }
         }

         return dp[0][0];

    }
};