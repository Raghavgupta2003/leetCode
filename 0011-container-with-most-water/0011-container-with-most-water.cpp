class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l =0;
        int r = heights.size()-1;
        
        int maxiArea = INT_MIN;
        while(l<=r){
            int minHeight = min(heights[l], heights[r]);

            maxiArea = max(maxiArea, minHeight * (r-l));

            if(minHeight == heights[l]) l++;
            else r--;


        }
        return maxiArea;
    }
};