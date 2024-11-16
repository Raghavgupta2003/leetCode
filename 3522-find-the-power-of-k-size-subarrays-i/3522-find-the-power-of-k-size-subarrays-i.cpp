// class Solution {
// public:
//     vector<int> resultsArray(vector<int>& nums, int k) {
//         vector<int> v;
// // outer loop runs (nums.size()-k+1) because size of subarray is k.
//         for(int i=0;i<nums.size()-k+1;i++){ 
//             int cnt = 0;
//             int max = -2;
//             bool flag = false;
//             int j;
// // the inner loop runs (k-1) times
//             for(j=i;j<i+k-1;j++){  
//                  cout<<nums[j]<<" ";
//                 if(nums[j+1]-nums[j] != 1){
// //checking the sub array is consecutive or not.
//                     v.push_back(-1);
//                     flag = true;
//                     break;
//                 }
//                 if(nums[j]>=max) max = nums[j];
//             }
//             if(nums[j]>=max) max = nums[j]; 
// //check for last element of subarray outside the inner loop because it runs (k-1) times, not k times.
//             cout<<nums[j]<<endl;
//             if(flag == false) v.push_back(max); 
// //if sub array is consecutive push_back maximum value of subarray
//         }
//         return v;
//     }
// };


class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        vector<int> v(nums.size(),1);
        for(int i=1;i<nums.size();i++){
            if(nums[i]==nums[i-1]+1) v[i] = v[i-1]+1;
        }
        vector<int> ans;
        for(int i=k-1; i<nums.size();i++){
            if(v[i]>=k) ans.push_back(nums[i]);
            else ans.push_back(-1);
        }
        return ans;
    }
};