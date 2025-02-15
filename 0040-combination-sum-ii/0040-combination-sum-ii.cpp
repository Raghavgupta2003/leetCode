class Solution {
public:
    void comb2(int idx, vector<int>& arr,int target, vector<vector<int>>& ans, vector<int> &v){
    
        if(target == 0){
            ans.push_back(v);
            return;
        }

       for(int i=idx; i<arr.size(); i++){
        if(i > idx && arr[i] == arr[i-1]) continue;
        // if(target < arr[i]) break;
        if(target >= arr[i]){
            v.push_back(arr[i]);
            comb2(i+1, arr, target-arr[i], ans, v);
            v.pop_back();
            
        }else{
            break;
        }
       }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> v;
        comb2(0, candidates, target, ans, v);
        
        return ans;
    }
};