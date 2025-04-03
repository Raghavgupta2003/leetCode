class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
//---------- prefix max Array--------
        int n = nums.size();
        vector<int> premax;
        premax.push_back(nums[0]);
        int maxi = nums[0];
        for(int i=1; i<nums.size(); i++){
            maxi = max(maxi, nums[i]);
            premax.push_back(maxi);
        }
        for(int i=0; i<nums.size(); i++){
            cout<<premax[i]<<" ";
        }
        cout<<endl;
//----------sufix max array-------------
        vector<int> sufmax(n);
        sufmax[n-1] = nums[n-1];
        maxi = nums[n-1];
        for(int i=n-2; i>=0; i--){
            maxi = max(maxi, nums[i]);
            sufmax[i] = maxi;
        }
        for(int i=0; i<nums.size(); i++){
            cout<<sufmax[i]<<" ";
        }
        cout<<endl;
//---------checking for j ----------
        long long maxi_ans = 0;
        for(int j=1; j<n-1; j++){
            long long ans = (long long) (premax[j-1] - nums[j]) * sufmax[j+1];
            maxi_ans = max(maxi_ans, (long long)ans);
        }
        return maxi_ans;
    }
};