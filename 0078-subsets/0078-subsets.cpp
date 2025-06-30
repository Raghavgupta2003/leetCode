class Solution {
public:
    void helper(int i, vector<vector<int>>& ans, vector<int>& help, vector<int>& nums){
        if(i>= nums.size()){
            ans.push_back(help);
            return;
        }
        
        //pick
        help.push_back(nums[i]);
        helper(i+1, ans, help, nums);
        help.pop_back();

        //not pick
        helper(i+1, ans, help, nums);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> help;
        helper(0, ans, help, nums);
        return ans;
    }
};