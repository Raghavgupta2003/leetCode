class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        vector<int> v;
        for(int i=0;i<nums.size()-k+1;i++){
            int cnt = 0;
            int max = -2;
            bool flag = false;
            int j;
            for(j=i;j<i+k-1;j++){
                 cout<<nums[j]<<" ";
                if(nums[j+1]-nums[j] != 1){
                    v.push_back(-1);
                    flag = true;
                    break;
                }
                if(nums[j]>=max) max = nums[j];
            }
            if(nums[j]>=max) max = nums[j];
            cout<<nums[j]<<endl;
            if(flag == false) v.push_back(max);
        }
        return v;
    }
};