class Solution {
public:
    bool doesAliceWin(string s) {
        int cnt = 0;
        for(int i=0; i<s.size(); i++){
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u'){
                cnt++;
            }
        }
        if(cnt == 0) return false; //bob wins, he have to even i.e. 0
        if(cnt % 2 != 0) return true; //alice win he has remove full string
        return true;  //Alice wins, this is case where vowels are even, so first Alice remove odd number(that is total -1), then bob remove 0 volweled string, then again alice remove everything, so alice wins.
    }
};