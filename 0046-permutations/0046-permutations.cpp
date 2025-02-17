// class Solution {
// public:
//     void permutations(vector<int>& arr, vector<vector<int>> &ans, vector<int>& v,  unordered_map<int, int> &m){
//         if(v.size()== arr.size()){
//             ans.push_back(v);
//             return;
//         }

//         for(int i=0; i<arr.size(); i++){
//             if(m.find(arr[i]) == m.end()){
//                 v.push_back(arr[i]);
//                 m[arr[i]] = 1;
//                 permutations(arr, ans, v, m);
//                 m.erase(arr[i]);
//                 v.pop_back();
//             }
//         }
//     }
//     vector<vector<int>> permute(vector<int>& nums) {
//         vector<vector<int>> ans;
//         vector<int> v;
//         unordered_map<int, int> m;
//         permutations(nums, ans, v, m);
//         return ans;
//     }
// };

class Solution {
public:
    void permutations(int idx, vector<int>& arr, vector<vector<int>> &ans){
        if(idx >= arr.size()){
            ans.push_back(arr);
            return;
        }

        for(int i=idx; i<arr.size(); i++){
            swap(arr[idx],arr[i]);
            permutations(idx+1, arr, ans);
            swap(arr[idx],arr[i]); 
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> v;
        unordered_map<int, int> m;
        permutations(0, nums, ans);
        return ans;
    }
};