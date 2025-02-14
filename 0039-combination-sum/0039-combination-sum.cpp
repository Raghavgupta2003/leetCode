class Solution {
public:
    void combination(int idx,vector<int>& candidates,int target,vector<vector<int>>& ans,vector<int>& v){
        if(idx >= candidates.size()){
            if(target == 0){
                ans.push_back(v);
            }
            return;
        }

        if(target >= candidates[idx]){
            //pick
            v.push_back(candidates[idx]);
            combination(idx, candidates, target-candidates[idx], ans, v); //same index can be pushed multiple times.
            v.pop_back();
        }
        combination(idx+1, candidates, target, ans, v); //since we are changing values in parameters so, target was not updated. so, we use previous value of target here.
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> v;
        combination(0,candidates,target,ans,v);
        return ans;
    }
};