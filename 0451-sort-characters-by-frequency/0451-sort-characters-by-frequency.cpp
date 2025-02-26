class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> m;
        for(int i=0; i<s.size(); i++){
            m[s[i]]++;
        }
        vector<pair<char,int>> v;
        v.assign(m.begin(),m.end());
        sort(v.begin(),v.end(),[](pair<char,int> a, pair<char,int> b){
            return a.second > b.second;
        });
        string str = "";
        for(int i=0; i<v.size();i++){
            pair<char, int> p = v[i];
            for(int j=0; j<p.second; j++){
                str+=p.first;
            }
        }
        return str;
    }
};