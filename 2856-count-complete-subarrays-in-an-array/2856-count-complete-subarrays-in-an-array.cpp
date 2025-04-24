class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int n = nums.size();
        set<int> s;
        for(int i=0; i<n; i++){
            s.insert(nums[i]);
        }

        int dist = s.size();
        int cnt = 0;
        for(int i=0; i<n; i++){
            set<int> se;
            for(int j=i; j<n; j++){
                se.insert(nums[j]);
                if(se.size() == dist) cnt++;
            }
        }

        return cnt;
    }
};