class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        // left to right profit
        vector<int> leftTOright(n, 0);
        int mini = prices[0];
        for(int i=1; i<prices.size(); i++){
            if(mini >= prices[i]) mini =  prices[i];

            leftTOright[i] = max(leftTOright[i-1], prices[i]-mini);
        }
        //right to left profit
        vector<int> rightTOleft(n, 0);
        int maxi = prices[n-1];
        for(int i=n-2; i>=0; i--){
            if(maxi <= prices[i]) maxi =  prices[i];

            rightTOleft[i] = max(rightTOleft[i+1], maxi - prices[i]);
        }
        //combining both
        int ans = 0;
        for(int i=0; i<n; i++){
            ans = max(ans, leftTOright[i]+rightTOleft[i]);
        }

        return ans;

    }
};