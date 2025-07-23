class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        vector<int> nse(n, n);
        for(int i=n-1; i>=0; i--){
            while(st.size() > 0 && heights[st.top()] >= heights[i]){
                st.pop();
            }
            if(st.size() > 0) nse[i] = st.top();

            st.push(i);
        }

        stack<int> st1;
        vector<int> pse(n, -1);
        for(int i=0; i<n; i++){
            while(st1.size() > 0 && heights[st1.top()] >= heights[i]){
                st1.pop();
            }
            if(st1.size() > 0) pse[i] = st1.top();

            st1.push(i);
        }

        int area = 0;
        for(int i=0; i<n; i++){
            area = max(area, heights[i] * (nse[i]-pse[i]-1));
        }
        return area;
    }
};