class Solution {
public:
    int minMaxDifference(int num) {
        string num1 = to_string(num);
        char firstMax;
        for(int i=0; i<num1.size(); i++){
            if(num1[i] != '9'){
                firstMax = num1[i];
                break;
            }
        }
        for(int i=0; i<num1.size(); i++){
            if(num1[i] == firstMax) num1[i] = '9';
        }
        int a = stoll(num1);
        //----------------------------------------
        string num2 = to_string(num);
        char firstMin;
         for(int i=0; i<num2.size(); i++){
            if(num2[i] != '0'){
                firstMin = num2[i];
                break;
            }
        }
        for(int i=0; i<num2.size(); i++){
            if(num2[i] == firstMin) num2[i] = '0';
        }
        int b = stoll(num2);
        return a-b;
        
    }
};