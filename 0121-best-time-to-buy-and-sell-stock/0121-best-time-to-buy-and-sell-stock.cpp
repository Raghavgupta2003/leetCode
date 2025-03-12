class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini = INT_MAX;
        int final_ans = 0;
        for(int i=0; i<prices.size(); i++){
            if(mini >= prices[i]){
                mini = prices[i];
            }
            int ans = prices[i]-mini;
            final_ans = max(final_ans, ans);
        }
        return final_ans;
    }
};