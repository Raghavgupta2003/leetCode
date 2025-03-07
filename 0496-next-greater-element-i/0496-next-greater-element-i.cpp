class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> nse(nums2.size(), -1);
        stack<int> st;
        st.push(nums2[nums2.size()-1]);
        int n = nums2.size();
        for(int i=n-1; i>=0; i--){
            while(st.size()>0 && st.top() <= nums2[i]){
                st.pop();
            }
            if(st.size()>0) nse[i]  = st.top();

            st.push(nums2[i]);
        }


        unordered_map<int, int> m;
        for(int i=0; i<nums2.size(); i++){
            m[nums2[i]] = nse[i];
        }

        vector<int> ans;
        for(int i=0; i<nums1.size(); i++){
            if(m.find(nums1[i]) != m.end()){
                ans.push_back(m[nums1[i]]);
            }
        }

        return ans;
        
    }
};