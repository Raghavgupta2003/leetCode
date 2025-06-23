class Solution {
public:
    int maxVowels(string s, int k) {
        // int n = s.size();
        // int windowLen = 0;

        // int maxVowel = 0;
        // int cntVowel = 0;
        // int l = 0;
        // int r = 0;
        // while(r < n){
        //     if(s[r] == 'a' || s[r] == 'e' || s[r] == 'i' || s[r] == 'o' || s[r] == 'u'){
        //         cntVowel++;
        //     }
        //     windowLen++; //****length of window***

        //     while(windowLen > k && l<=r){
        //          if(s[l] == 'a' || s[l] == 'e' || s[l] == 'i' || s[l] == 'o' || s[l] == 'u') cntVowel--;

        //          windowLen--;
        //          l++;
        //     }

        //     maxVowel = max(maxVowel, cntVowel);
        //     r++;
        // }

        // return maxVowel;

        //---------------------------------------------------------
        //since windowSize is fixed, we need not to take inner while loop

          int n = s.size();
        int windowLen = 0;

        int maxVowel = 0;
        int cntVowel = 0;
        int l = 0;
        int r = 0;
        while(r < n){
            if(s[r] == 'a' || s[r] == 'e' || s[r] == 'i' || s[r] == 'o' || s[r] == 'u'){
                cntVowel++;
            }

            if(r-l+1 == k){
                maxVowel = max(maxVowel, cntVowel);

                 if(s[l] == 'a' || s[l] == 'e' || s[l] == 'i' || s[l] == 'o' || s[l] == 'u') cntVowel--;
                 
                 l++;
                 r++;
            }
            else{
                r++;
            }
        }

        return maxVowel;
    }
};