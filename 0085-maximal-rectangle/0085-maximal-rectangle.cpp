class Solution {
public:
    int getMaxArea(vector<int> &arr) {
        // Your code here
        int n = arr.size();
        stack<int> st;
        st.push(n-1);
        vector<int> nse(n, n);
        for(int i=n-2; i>=0; i--){
            while(st.size()>0 && arr[st.top()]>=arr[i]){
                st.pop();
            }
            if(st.size() != 0)  nse[i] = st.top() ;
            st.push(i);
        }
        
        stack<int> s;
        s.push(0);
        vector<int> pse(n, -1);
        for(int i=1; i<n; i++){
            while(s.size()>0 && arr[s.top()]>=arr[i]){
                s.pop();
            }
            if(s.size() != 0) pse[i] = s.top();
            s.push(i);
        }
        
        int maxi = 0;
        for(int i=0; i<n; i++){
            int area = (nse[i] - pse[i] - 1) * arr[i];
            maxi = max(maxi, area);
        }
        
        return maxi;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size(); //row
        int n = matrix[0].size(); //col
        
        vector<int> heights(n, 0);
        
        int max_area = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(matrix[i][j] == '1'){
                    heights[j] += 1;
                }
                else{
                    heights[j] = 0;
                }
            }
            max_area = max(max_area, getMaxArea(heights));
        }
        return max_area;
    }
};