class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if(s1.size() != s2.size()) return false;
        if(s1 == s2) return true;
        
        vector<char> v;
        for(int i=0; i<s1.size(); i++){
            if(s1[i] != s2[i]){
                v.push_back(i);
            }
        }

        if(v.size() == 2){
            swap(s2[v[0]] , s2[v[1]]);
            if(s1 == s2) return true;
        }

        return false;
    }
};