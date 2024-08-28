class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // int ans=0;
        // for(int i=0;i<prices.size();i++){
        //     for(int j=i+1;j<prices.size();j++){
        //         ans=max(ans,(prices[j]-prices[i]));
        //     }
        // }
        // return ans;

        int min_val=INT_MAX;
        int max_profit=0;
        for(int i=0;i<prices.size();i++){
            if(prices[i]<min_val) min_val=prices[i];
            
            max_profit = max(prices[i]-min_val,max_profit);
           
        }
        return max_profit;
    }
};