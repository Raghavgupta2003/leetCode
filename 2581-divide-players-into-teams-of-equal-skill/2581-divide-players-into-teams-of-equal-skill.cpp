class Solution {
public:
    long long dividePlayers(vector<int>& skills) {
        sort(skills.begin(),skills.end());

  // for sum of pair equal then first should be smllest and second should be largest or vice-versa. that is why we sorted it to get pairs by two pointer technique.
       
        

        long long i=0;
        long long j=skills.size()-1;  
        long long sum = skills[i] + skills[j];
        long long chem = skills[i] * skills[j];
        i++;
        j--;
        while(i<=j){
            if(sum == skills[i] + skills[j]){
                int pdt = skills[i] * skills[j];
                chem += pdt;
            }
            else{
                return -1;
            }
            i++;
            j--;
        }

        return chem;
    }
};