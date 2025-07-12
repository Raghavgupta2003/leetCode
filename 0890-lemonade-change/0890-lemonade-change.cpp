class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int count5 = 0;
        int count10 = 0;
        int count20 = 0;
        for(int i=0; i<bills.size(); i++){
             if(bills[i] == 5){
                count5 += 1;
             }
             else{
                if(bills[i] == 10){
                    if(count5 >= 1){
                        count5 -= 1;
                        count10 += 1;
                    }else{
                        return false;
                    }
                }
                else if(bills[i] == 20){
                        if(count10 >= 1 && count5>=1){
                            count10 -= 1;
                            count5 -= 1;

                            count20 += 1;
                        }
                        else if(count5 >= 3){
                            count5 -= 3;

                            count20 += 1;
                        }
                        else{
                            return false;
                        }
                }
             }
        }
        return true;
    }
};