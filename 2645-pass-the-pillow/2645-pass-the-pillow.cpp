class Solution {
public:
    int passThePillow(int n, int time) {
        int k=1;
        int person =1;
        while(k<=time){
            
            if(person == n) person*=(-1);
            if(person == -1) person*=(-1);
            person++;
            k++;
        }
        return abs(person);
        
    }
};