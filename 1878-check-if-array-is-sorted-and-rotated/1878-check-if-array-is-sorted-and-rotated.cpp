class Solution {
public:
    bool check(vector<int>& nums) {
        int pos = 0;
        for(int i=1; i<nums.size(); i++){
            if(nums[i-1] > nums[i]) pos = i;
        }

        vector<int> v = nums;
        sort(v.begin(), v.end());

        bool flag = true;
        for(int i=0;i<nums.size();i++){
            if(v[i] != nums[(i+pos)% nums.size()]){
                return false;
            }
        }

        return true;

    }
};
