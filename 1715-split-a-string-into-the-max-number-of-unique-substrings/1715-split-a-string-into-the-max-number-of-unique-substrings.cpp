// class Solution {
// public:
//     int maxUniqueSplit(string s) {
//         set<string> st;
//         string str = "";
//         for(int i=0;i<s.size();i++){
//             str+=s[i];
//             if(st.find(str)==st.end()){
//                 st.insert(str);
//                 str="";
//             }
//         }
//         cout<<str<<" ";
//         return st.size();
//     }
// };

class Solution {
public:
    int maxUniqueSplit(string s) {
        unordered_set<string> seen;
        return backtrack(0, s, seen);
    }
private:
    int backtrack(int start, const string& s, unordered_set<string>& seen) {
        if (start == s.size()) {
            return 0;
        }
        int maxSplits = 0;
        for (int end = start + 1; end <= s.size(); ++end) {
            string substring = s.substr(start, end - start);
            if (seen.find(substring) == seen.end()) {
                seen.insert(substring);
                maxSplits = max(maxSplits, 1 + backtrack(end, s, seen));
                seen.erase(substring);
            }
        }
        return maxSplits;
    }
};

