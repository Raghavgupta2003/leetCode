class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        set<char> s;
        for(int i=0; i<brokenLetters.size(); i++){
            s.insert(brokenLetters[i]);
        }
        vector<string> v;
        stringstream ss(text);
        string str;
        while(ss>>str){
            v.push_back(str);
        }
        int cnt = 0;
        for(int i=0; i<v.size(); i++){
            string str = v[i];
            bool flag = true;
            for(int j=0; j<str.size(); j++){
                char ch = str[j];
                if(s.find(ch)!=s.end()){
                    flag = false;
                    break;
                }
            }
            if(flag==true) cnt++;
        }
        return cnt;
    }
};