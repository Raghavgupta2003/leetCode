class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {

    //-----------By prefixSum----------------
        // int n = nums.size();
        // vector<int> ans(n, -1);
        // vector<long long> prefix(n);
        // prefix[0] = nums[0];
        // for(int i=1; i<nums.size(); i++){
        //     prefix[i] = prefix[i-1] + nums[i];
        // }
        
        // //we start from index k and end before n-k, as we know, we will not ger k element before it and after it
        // for(int i=k; i<n-k; i++){
        //     long long sumTillNplusK = prefix[i+k];
        //     long long SumbeforeNminusK = 0;

        //     if(i-k != 0) SumbeforeNminusK = prefix[i-k-1];
        //     ans[i] = (sumTillNplusK - SumbeforeNminusK)/(2*k + 1); //avg
        //     //number = k(left) + k(right) + 1(ele itself)
        // }

        // return ans;

    //-----------------Sliding window----------------------

        int n = nums.size();

        vector<int> res(n, -1);
         if (2 * k + 1 > n) return res;

        //array filling start from "k" to "n-k"

        int i=k;
        //range left to right
        int l = 0;
        int r = i + k;

        long long currSum = 0;
        for(int i=l; i<=r; i++){
            currSum += nums[i];
        } 

        res[i] = currSum/(2*k+1); //k left + k right + ith element itself
        i++;

        while(r+1 < n){
            currSum -= nums[l];
            currSum += nums[r+1];

            l++;
            r++;

            res[i] = currSum/(2*k + 1);
            i++;
        }

        return res;

    }
};

