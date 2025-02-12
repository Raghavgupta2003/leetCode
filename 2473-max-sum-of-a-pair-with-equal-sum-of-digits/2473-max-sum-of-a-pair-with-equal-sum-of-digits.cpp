class Solution {
public:
    int sum_of_digits(int n){
        int sum = 0;
        while(n>0){
            sum += (n%10);
            n/=10;
        }
        return sum;
    }
    int maximumSum(vector<int>& nums) {
        map<int, int> m;
        int maxi = -1;
        for(int i=0; i<nums.size(); i++){
            int SUM = sum_of_digits(nums[i]);
           
            if(m.find(SUM)!=m.end()){
                maxi = max(maxi, m[SUM] + nums[i]);
                if(m[SUM] < nums[i])  m[SUM] = nums[i];
            }
            else{
                m[SUM] = nums[i];
            }
        }

        for(auto pair : m){
            cout<<pair.first<<" "<<pair.second<<endl;
        }
        return maxi;
    }
};