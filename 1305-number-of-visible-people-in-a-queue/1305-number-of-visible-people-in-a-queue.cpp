class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        int n = heights.size();
        vector<int> ans(n, 0); //if no greater then can see all
        stack<int> st;
        st.push(n-1);
        
        for(int i=n-2; i>=0; i--){
            int cnt = 0;
            while(st.size()>0 && heights[st.top()] < heights[i]){
                cnt++;
                st.pop();
            }
            if(st.size() > 0)cnt++;
            ans[i]=cnt;
            st.push(i);
        }
         
        

        return ans;

    }
};