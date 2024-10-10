// class Solution {
// public:
//     int maxWidthRamp(vector<int>& nums) {
//         int max = INT_MIN;
//         for(int i=0;i<nums.size();i++){
//             for(int j=i;j<nums.size();j++){
//                 if(nums[i]<=nums[j]){
//                     int ramp = j-i;
//                     if(ramp>=max) max = ramp;
//                 }
//             }
//         }
//         return max;
//     }
// };


class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n=nums.size();
        stack<int> minst;
        minst.push(0);
        for(int i=1;i<n;i++){
            if(nums[i]<=nums[minst.top()]) minst.push(i);
        }

        int res = INT_MIN;
        for(int j=n-1;j>=0;j--){
            while(minst.size()>0 && nums[minst.top()]<=nums[j]){
                res = max(res,j-minst.top());
                minst.pop();
            }
        }
        return res;
    }
};
