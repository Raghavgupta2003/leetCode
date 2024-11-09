class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        vector<int> prefix;
        prefix.push_back(nums[0]);
        for(int i=1;i<nums.size();i++){
            int x = prefix[i-1] ^ nums[i];
            prefix.push_back(x);
        }

        for(int i=0;i<prefix.size();i++){
           cout<<prefix[i]<<" ";
        }

        vector<int> ans;
        int bit = pow(2,maximumBit) - 1;

        // we have to find a value so that
        // value % prefixarrayEle == pow(2,maximumBit) - 1;

        //for example 
        //nums = [0,1,1,3], maximumBit = 2
        //for this->  bit = pow(2,maximumBit)-1 = pow(2,2)-1 = 4-1 = 3;
        //for this prefix array is  = [0 1 0 3];
        // value ^ 0 = 3    ---> value = 3 ^ 0 = 3;
        // value ^ 1 = 3    ---> value = 3 ^ 1 = 2;
        // value ^ 0 = 3    ---> value = 3 ^ 0 = 3;
        // value ^ 3 = 3    ---> value = 3 ^ 3 = 0;

        for(int i=0;i<prefix.size();i++){
            int x = prefix[i] ^ bit;
            ans.push_back(x);
        }
        reverse(ans.begin(),ans.end());
        return ans;

    }
};