class Solution {
public:
    bool areSentencesSimilar(string sent1, string sent2) {
        vector<string> s1;
        vector<string> s2;
        string sentence1;
        string sentence2;
        if(sent1.size()>=sent2.size()){
            sentence2 = sent1;
            sentence1 = sent2;             //sent2 contain larger string
        }
        else{
            sentence1 = sent1;
            sentence2 = sent2;
        }

        string word;
        stringstream ss(sentence1);
        while(ss>>word){
            s1.push_back(word);
        }

        stringstream sss(sentence2);
        while(sss>>word){
            s2.push_back(word);
        }

        int i = 0;
        while(i<s1.size() && i<s2.size()){
            if(s1[i]==s2[i]) {
                i++;
            }
            else break;
        }


        int end1 = s1.size()-1;
        int end2 = s2.size()-1;
        while(end1>=0 && end2>=0){
            if(s1[end1]==s2[end2]){
                end1--;
                end2--;
            }
            else break;
        }

        return (i>end1);
        //  when end of smallest string become less than i, then they are similar else not.
        //dry run testcase and understand.
    }
};