class Solution {
public:
    string intToRoman(int num) {
        //we also stored the values of 4, 9, 40, 90, ..
        //because if not done so, then 4 = IIII
        //40 = XXXX
        //but 4 times a value is not allowed.
        vector<pair<int, string>> v;
        v.push_back({1, "I"});
        v.push_back({4, "IV"});
        v.push_back({5, "V"});
        v.push_back({9, "IX"});
        v.push_back({10, "X"});
        v.push_back({40, "XL"});
        v.push_back({50, "L"});
        v.push_back({90, "XC"});
        v.push_back({100, "C"});
        v.push_back({400, "CD"});
        v.push_back({500, "D"});
        v.push_back({900, "CM"});
        v.push_back({1000, "M"});
        
        string str = "";
        while(num > 0){
            for(int i=v.size()-1; i>=0; i--){
                int integer = v[i].first;
                string roman = v[i].second;

                if(integer <= num){
                    str += roman;
                    num -= integer;
                    break;
                }
            }
        }

        return str;
    }
};