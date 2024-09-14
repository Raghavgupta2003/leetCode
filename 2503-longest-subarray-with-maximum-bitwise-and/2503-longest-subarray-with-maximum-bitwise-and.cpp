class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int max=INT_MIN;
        for(int i=0;i<nums.size();i++){
            if(max<nums[i]) max=nums[i];
        }
        // vector<int> v;
        // for(int i=0;i<nums.size();i++){
        //     if(nums[i]==max) v.push_back(nums[i]);
        //     if(v.size()>0 && nums[i]!=max) break;
        // }
        // return v.size();
      

        vector<int> v;
        int cnt=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==max) cnt++;
            if(cnt>0 && nums[i]!=max){
                v.push_back(cnt);
                cnt=0;

            }
        }
        v.push_back(cnt); //if cnt is not pushedback into vector.

        int m=INT_MIN; //max value of v;
        for(int i=0;i<v.size();i++){
            if(m<=v[i]) m=v[i];
        }

        return m;
    }
};