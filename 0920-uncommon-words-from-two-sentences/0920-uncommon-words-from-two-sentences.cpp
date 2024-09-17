class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        vector<string> ans;

        vector<string> str1;
        stringstream ss(s1+" "+s2);
        string temp;
        while(ss>>temp){
            str1.push_back(temp);
        }

        for(int i=0;i<str1.size();i++){
            cout<<str1[i]<<" ";
        }

        unordered_map <string,int> m;
        for(int i=0;i<str1.size();i++){
            m[str1[i]]++;
        }
        for(auto pair : m){
            if(pair.second==1)
            ans.push_back(pair.first);
        }
        return ans;
    }
};