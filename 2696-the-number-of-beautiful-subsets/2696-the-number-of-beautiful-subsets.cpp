class Solution {
public:
    int fxn(int i, vector<int>& nums, int k, vector<int>& help, unordered_map<int, int>& m){
        if(i>=nums.size()){
            return 1;
        }

        //pick
        int pick = 0;
        //given abs(a-b) = k
        // a-b = +-(k)
        // a-k = b && a+k = b
        if(m.find(nums[i]-k) == m.end()   &&  m.find(nums[i]+k) == m.end()){ //not found
            m[nums[i]]++;
            help.push_back(nums[i]);

            pick = fxn(i+1, nums, k, help, m);

            m[nums[i]]--;
            if(m[nums[i]] == 0) m.erase(nums[i]);
            help.pop_back();
        }

        //not pick
        int notpick = fxn(i+1, nums, k, help, m);

        return pick + notpick;
    }
    int beautifulSubsets(vector<int>& nums, int k) {
        vector<int> help;
        unordered_map<int, int> m;
        int x = fxn(0, nums, k, help, m);

        return x-1; //since empty subset is also counted
    }
};