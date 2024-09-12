class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        set<int> s;
        for(int i=0;i<allowed.size();i++){
            s.insert(allowed[i]);
        }
        int cnt=0;
        for(int i=0;i<words.size();i++){
            string str = words[i];
            for(int i=0;i<str.size();i++){
                if(s.find(str[i])==s.end()){
                    cnt++;
                    break;
                }
            }
        }
        return words.size()-cnt;
    }
};