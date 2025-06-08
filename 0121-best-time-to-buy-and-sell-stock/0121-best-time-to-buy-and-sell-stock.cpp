class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //--------Brute Force---------
        // int maxi = INT_MIN;
        // for(int i=0; i<prices.size(); i++){
        //     // i is consider as minimum
        //     for(int j=i+1; j<prices.size(); j++){
        //         maxi = max(maxi, prices[j]-prices[i]);
        //     }
        // }
        // if(maxi < 0) return 0;
        // return maxi;


        //------Optimise------

        // we keep track of minimum

        int mini = INT_MAX;
        int maxProfit = INT_MIN;

        for(int i=0; i<prices.size(); i++){
            if(mini > prices[i]){
                mini = prices[i];
            } 
            
            maxProfit = max(maxProfit, prices[i]-mini);
        }

        return maxProfit;
    }
};