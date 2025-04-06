// class Solution {
// public:
//     static bool compare(vector<int> a, vector<int> b){
//         return a.size()<b.size();
//     }
//     vector<vector<int>> ans;
//     void helper(int idx, int prev, vector<int>& nums, vector<int> &v){
//         if(idx >= nums.size()){
//             ans.push_back(v);
//             return;
//         }

//         if(prev == -1 || nums[prev] % nums[idx] == 0){ //prev == -1 when size 0;
//             v.push_back(nums[idx]);
//             helper(idx+1, idx, nums, v); //prev is updated with idx
//             v.pop_back();
//         }

//         helper(idx+1, prev, nums, v);
//     }
//     vector<int> largestDivisibleSubset(vector<int>& nums) {
//         sort(nums.begin(), nums.end(), greater<int>()); //sort and reverse
//         int idx = 0;
//         vector<int> v;
//         helper(idx, -1, nums, v);

//         sort(ans.begin(), ans.end(), compare);

//         return ans[ans.size()-1];
//     }
// };



class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> dp(nums.size(), 1), prev(nums.size(), -1);
        int maxi = 0;
        for (int i = 1; i < nums.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] % nums[j] == 0 && dp[i] < dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                    prev[i] = j;
                }
            }
            if (dp[i] > dp[maxi]) maxi = i;
        }
        vector<int> res;
        for (int i = maxi; i >= 0; i = prev[i]) {
            res.push_back(nums[i]);
        }
        return res;
    }
};