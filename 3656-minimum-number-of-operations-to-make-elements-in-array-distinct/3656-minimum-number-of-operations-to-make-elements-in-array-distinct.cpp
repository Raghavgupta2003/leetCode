class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        if(nums.size() == 0) return 0; //already distint;
        if(nums.size() == 1) return 0;
        if(nums.size() == 2){
            if(nums[0] == nums[1]) return 1;
            return 0;
        }
        int cnt = 0;
        int i=0;
        for(i=0; i<nums.size(); i+=3){
            set<int> s;
            for(int j=i; j<nums.size(); j++){
                s.insert(nums[j]);
            }
            if(s.size() == nums.size()-i) return cnt;
            cnt++;
        }
        return cnt;
    }
};