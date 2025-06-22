class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> m;
        int MaxLength = 0;
        int j = 0;
        for(int i=0; i<n; i++){
            m[nums[i]]++;

            while(m[nums[i]] > k && j<=i){
                m[nums[j]]--; //decreasing the freq
                j++;
            }

            MaxLength = max(MaxLength, i-j+1);
        }

        return MaxLength;
    }
};