class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        //-----by division operator-----

        // int pdt=1;
        // int pdt1=1;
        // int noz = 0;
        // for(int i=0;i<nums.size();i++){
        //     if(nums[i]==0) noz++;

        //     pdt*=nums[i];

        //     if(nums[i]!=0) pdt1*=nums[i];
        //     else continue;
        // }
        // if(noz>1) pdt1=0;
        // for(int i=0;i<nums.size();i++){
        //     if(nums[i]!=0)
        //     nums[i] = pdt/nums[i];
        //     else
        //     nums[i]=pdt1;
        // }
        // return nums;

        //------------------------------------------
        int n=nums.size();

        //pre array
        vector<int> pre(n);
        pre[0]=1;
        for(int i=1;i<n;i++){
            pre[i]=pre[i-1]*nums[i-1];
        }

        //suf array
        vector<int> suf(n);
        suf[n-1]=1;
        for(int i=n-2;i>=0;i--){
            suf[i]=suf[i+1]*nums[i+1];
        }
        

        vector<int> ans;
        for(int i=0;i<n;i++){
            ans.push_back(pre[i]*suf[i]);
        }
        return ans;
    }
};