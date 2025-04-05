class Solution {
public:
    void subset(int idx, vector<int>& nums, vector<int>& v, int xo){
        if(idx >= nums.size()){
            v.push_back(xo);
            return;
        }

        subset(idx+1, nums, v, xo ^ nums[idx]); //pick
        subset(idx+1, nums, v, xo); //notpick
    }
    int subsetXORSum(vector<int>& nums) {
        if(nums.size() == 0) return 0;

        vector<int> v;
        int xo = 0;
        subset(0, nums, v, xo);

        int sum = 0;

        for(int i=0; i<v.size(); i++){
            // cout<<v[i]<<" ";
            sum += v[i];
        }
        return sum;
    }
};