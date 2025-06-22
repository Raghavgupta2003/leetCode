class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans(n, -1);
        vector<long long> prefix(n);
        prefix[0] = nums[0];
        for(int i=1; i<nums.size(); i++){
            prefix[i] = prefix[i-1] + nums[i];
        }

        for(int i=k; i<n-k; i++){
            long long sumTillNplusK = prefix[i+k];
            long long SumbeforeNminusK = 0;

            if(i-k != 0) SumbeforeNminusK = prefix[i-k-1];
            ans[i] = (sumTillNplusK - SumbeforeNminusK)/(2*k + 1); //avg
            //number = k(left) + k(right) + 1(ele itself)
        }

        return ans;
    }
};