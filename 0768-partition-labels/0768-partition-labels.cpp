class Solution {
public:
    vector<int> partitionLabels(string s) {
        map<char, int> m;
        for(int i=0; i<s.size(); i++){
            m[s[i]] = i;
            //it will store last index of each element
        }

        vector<int> v;
        for(int i=0; i<s.size(); i++){
            int lastIdx = m[s[i]];
            string str = "";
            for(int j=i; j<=lastIdx; j++){
            // if any characters lastindex greater then we update lastIdx. 
                if(m[s[j]] > lastIdx) lastIdx = m[s[j]];
                str += s[j];
            }
            cout<<str<<" ";
            v.push_back(str.size());
            i += str.size()-1;
        }
        return v;
    }
};