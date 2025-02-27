class Solution {
public:
    int houserobberI(int idx, vector<int> &nums, vector<int> &dp){
        
        if(idx >= nums.size()) return 0;

        if(dp[idx]!= -1) return dp[idx];

        //pick
        int left = nums[idx] + houserobberI(idx+2, nums, dp);
        //not pick
        int right = 0 + houserobberI(idx+1, nums, dp);

        return dp[idx] = max(left, right);
    }
    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        int n = nums.size();
        vector<int> dp1(n, -1);
        vector<int> dp2(n, -1);
        vector<int> temp1;
        vector<int> temp2;
        for(int i=0; i<n; i++){
            if(i!=0) temp1.push_back(nums[i]);
            if(i!= n-1) temp2.push_back(nums[i]);
        }
        return max(houserobberI(0,temp1,dp1), houserobberI(0,temp2,dp2));
    }
};