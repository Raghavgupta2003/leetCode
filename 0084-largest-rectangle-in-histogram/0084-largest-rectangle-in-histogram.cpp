class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        //nge
        stack<int> st;
        st.push(n-1);
        vector<int> nse(n, n);
        for(int i=n-2; i>=0; i--){
            while(st.size()>0 && heights[st.top()] >= heights[i] ) st.pop();
            if(st.size() > 0) nse[i] = st.top();
            st.push(i);
        }

        for(int i=0; i<nse.size(); i++){
            cout<<nse[i]<<" "; 
        }
        cout<<endl;

        //PSE
        stack<int> gt;
        gt.push(0);
        vector<int> pse(n, -1);
        for(int i=0;  i<heights.size(); i++){
            while(gt.size()>0 && heights[gt.top()] >= heights[i] ) gt.pop();
            if(gt.size() > 0) pse[i] = gt.top();
            gt.push(i);
        }


        int maxi = INT_MIN;
        for(int i=0; i<pse.size(); i++){
            maxi = max(abs(pse[i]-nse[i]+1)*heights[i], maxi);
        }
        cout<<endl;



        return maxi;
    }
};