class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int xorVal = 0;
        for(int i=0; i<nums.size(); i++){
            xorVal ^= nums[i];
        }

        //Number of flips to make xorVal = k;
        //similar to 2220. Minimum Bit Flips to Convert Number

        int x = xorVal ^ k;

        //cnting set bit
        int cnt = 0;
        while(x){
            if(x%2 == 1) cnt++;
            x/=2;
        }

        return cnt;
    
    }
};