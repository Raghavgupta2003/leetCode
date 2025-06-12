class Solution {
public:
    int maxDifference(string s) {
        unordered_map<char, int> m;
        for(int i=0; i<s.size(); i++){
            m[s[i]]++;
        }

        int a1_max_odd = INT_MIN;
        int a2_min_even = INT_MAX;
        for(auto it : m){
            if(it.second % 2 != 0){
                a1_max_odd = max(a1_max_odd, it.second);
            }else{
                a2_min_even = min(a2_min_even, it.second);
            }
        }

        return a1_max_odd - a2_min_even;
    }
};