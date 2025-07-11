class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int trips = 0;
        sort(people.begin(), people.end());
        int i=0;
        int j=people.size()-1;
        while(i<=j){
            if(people[i] + people[j] <= limit){
                i++;
                j--;

                // means in a trip 2 persons go
                trips++;
            }
            else{ //people[i] + people[j] > limit
                //means only heavier person can go 
                j--;
                trips++;
            }
        }
        return trips;
    }
};