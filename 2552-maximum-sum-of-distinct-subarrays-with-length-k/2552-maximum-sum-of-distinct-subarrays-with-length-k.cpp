class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();

        int i=0;
        int j=0;
        long long currSum = 0;
        long long MaxSum = 0;
        set<int> s;

        while(i<n){
            // if condition voilates, start shrinking window
            while(s.find(nums[i]) != s.end()){
                currSum -= nums[j];
                s.erase(nums[j]);
                j++;
            }

            currSum += nums[i];
            s.insert(nums[i]);
               
            int window = (i-j+1);

            if(window == k){
                MaxSum = max(MaxSum , currSum);
                s.erase(nums[j]);
                currSum -= nums[j];
                i++;
                j++;
            }
            else i++;
        }
        return MaxSum;
    }
};