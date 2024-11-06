class Solution {
public:
    string compressedString(string word) {
        string comp = "";
        int freq = 1;
        char ch = word[0];

        for(int i=1;i<word.size();i++){
            if(word[i]==word[i-1] && freq<9){
                freq++;
            }
            else{
                comp += to_string(freq)+ch;
                freq = 1;
                ch = word[i];
            }
        }
        if(comp.length()<2*word.length()) comp += to_string(freq) + ch;
        return comp;
    }
};