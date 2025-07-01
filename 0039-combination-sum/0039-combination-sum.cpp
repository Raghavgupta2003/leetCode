class Solution {
public:
    void sum(int i, vector<vector<int>>& ans, vector<int>& help, vector<int>& arr, int target){
        if(i>=arr.size()){
            if(target == 0) ans.push_back(help);
            return;
        }

        //pick
        if(target >= arr[i]){
            help.push_back(arr[i]);
            sum(i, ans, help, arr, target-arr[i]);
            help.pop_back();
        }

        //not pick
        sum(i+1, ans, help, arr, target);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> help;
        sum(0, ans, help, candidates, target);

        return ans;
    }
};