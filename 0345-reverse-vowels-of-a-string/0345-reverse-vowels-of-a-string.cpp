class Solution {
public:
    bool isvowel(char ch){
        if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u')
        return true;

        if(ch=='A' || ch=='E' || ch=='I' || ch=='O' || ch=='U')
        return true;

        return false;
    }
    string reverseVowels(string s) {
        int l=0;
        int r=s.length()-1;
        while(l<r){
            if(!isvowel(s[l])) l++;
            else if(!isvowel(s[r])) r--;
            else{
                swap(s[l],s[r]);
                l++;
                r--;
            }
        }
        return s;
    }
};