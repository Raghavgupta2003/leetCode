class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> m;
        for(int i=0; i<nums.size(); i++){
            m[nums[i]]++;
        }
        int maxi = 0;
        for(auto it: m){
            if(it.second > maxi){
                maxi = it.second;
            }
        }
        int cnt =0;
        for(auto it : m){
            if(it.second == maxi) cnt+=it.second;
        }
        return cnt;
    }
};