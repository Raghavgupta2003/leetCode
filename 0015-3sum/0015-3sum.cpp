class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> ans;
        for(int i=0; i<nums.size(); i++){

            if(i > 0 && nums[i] == nums[i - 1]) continue; // to remove duplicate answers

            int j = i+1;
            int k = n-1;
            vector<int> v;
            while(j < k){
                if(nums[i] + nums[j] + nums[k] == 0){
                    v = {nums[i], nums[j], nums[k]};
                    // to remove duplicate answers
                    while(j<k && nums[j] == nums[j+1]) j++;
                    while(j<k && nums[k] == nums[k-1]) k--;
                    j++;
                    k--;
                    ans.push_back(v);
                }
                else if(nums[i] + nums[j] + nums[k] < 0){
                    j++;
                }
                else if(nums[i] + nums[j] + nums[k] > 0){
                    k--;
                }
            }
        }
        return ans;
    }
};