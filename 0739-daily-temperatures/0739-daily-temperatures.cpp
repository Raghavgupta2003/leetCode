class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> ngeIdx(n, -1);
        stack<int> st;
        st.push(n-1);
        for(int i=n-1; i>=0; i--){
            while(st.size()>0 && temperatures[st.top()]<=temperatures[i]){
                st.pop();
            }

            if(st.size() != 0) ngeIdx[i] = st.top();
            st.push(i);
        }
        vector<int> ans;
        for(int i=0; i<n; i++){
            if(ngeIdx[i] == -1) ans.push_back(0);
            else ans.push_back(ngeIdx[i] - i);
        }

        return ans;
    }
};