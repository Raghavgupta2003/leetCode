class Solution {
public:
    void helper(int i, set<vector<int>>& ans, vector<int>& help, vector<int>& nums){
        if(i>= nums.size()){
            ans.insert(help);
            return;
        }
        
        //pick
        help.push_back(nums[i]);
        helper(i+1, ans, help, nums);
        help.pop_back();

        //not pick
        helper(i+1, ans, help, nums);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        set<vector<int>> ans;
        vector<int> help;
        helper(0, ans, help, nums);

        vector<vector<int>> arr;
        arr.assign(ans.begin(),ans.end());

        sort(arr.begin(), arr.end());
        return arr;
    }
};