class Solution {
public:
    string sortVowels(string s) {
        vector<int> idx;
        vector<char> ele;
        for(int i=0; i<s.size(); i++){
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u' || s[i]=='A' || s[i]=='E' || s[i]=='I' || s[i]=='O' || s[i]=='U'){
                ele.push_back(s[i]);
                idx.push_back(i);
            }
        }

        sort(ele.begin(), ele.end());

        for(int i=0; i<idx.size(); i++){
            s[idx[i]] = ele[i];
        }

        return s;
        
    }
};