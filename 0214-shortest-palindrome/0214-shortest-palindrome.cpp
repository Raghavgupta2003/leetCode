// class Solution {
// public:
//     bool ispalindrome(string s){
//         int i=0;
//         int j=s.size()-1;
//         while(i<=j){
//             if(s[i]==s[j]){
//                 i++;
//                 j--;
//             }
//             else return false;
//         }
//         return true;
//     }
//     string shortestPalindrome(string s) {  
//         if(ispalindrome(s)) return s;
//         int idx=-1;      
//         for(int i=s.size()-1;i>=0;i--){
//             string str = s.substr(0,i);
//             if(ispalindrome(str)){
//                 idx=i;
//                 break;
//             }
//         }
//         cout<<idx<<endl;
//         string strTorev = s.substr(idx);
//         reverse(strTorev.begin(),strTorev.end());

//         return strTorev + s;
//     }
// };

class Solution {
public:
    string shortestPalindrome(string s) {
        string rev_s = s;
        reverse(rev_s.begin(), rev_s.end());
        
        // Create the new string: s + "#" + reverse(s)
        string new_s = s + "#" + rev_s;
        
        // Build the LPS (Longest Prefix Suffix) array
        vector<int> lps(new_s.size(), 0);
        
        // Compute the LPS array (similar to KMP algorithm)
        for (int i = 1; i < new_s.size(); i++) {
            int j = lps[i - 1];
            while (j > 0 && new_s[i] != new_s[j]) {
                j = lps[j - 1];
            }
            if (new_s[i] == new_s[j]) {
                j++;
            }
            lps[i] = j;
        }
        
        // The length of the longest palindrome prefix is given by lps.back()
        int longest_palindrome_prefix_length = lps.back();
        
        // The remaining part of the string (that isn't a palindrome)
        string to_add = s.substr(longest_palindrome_prefix_length);
        reverse(to_add.begin(), to_add.end());
        
        // Prepend the reversed remaining part to the original string
        return to_add + s;
    }
};
