class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        // vector<int> v;
        // int sum=0;
        // for(int i=0;i<nums.size();i++){
        //     sum+=nums[i];
        //     v.push_back(sum);
        // }
        // return v;

        //----------Without using extra space--------
        for(int i=1;i<nums.size();i++){
            nums[i]+=nums[i-1];
        }
        return nums;

    }
};