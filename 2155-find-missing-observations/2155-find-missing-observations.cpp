class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        vector<int> v;
        int sum = 0;
        for(int i=0;i<rolls.size();i++){
            sum+=rolls[i];
        }

        int Total_rolls = rolls.size()+n;

        int sum_of_n_rolls = (mean * Total_rolls)-sum;

        cout<<sum_of_n_rolls<< "     "<<n<<endl;

        int x=sum_of_n_rolls/n; //divided value
        int y=sum_of_n_rolls%n;  // mod value
        cout<<x<<" "<<y;

        //base case
        // if(x>6 || x<1) return {};
        if(sum_of_n_rolls < n  ||  x>6) return {};
        
        for(int i=0;i<n;i++){
            v.push_back(x); //push_backing divided value
        }
        int i=0;
        while(y>0){
            v[i]+=1;
            y--;
            if(v[i]>6) return {};
            i++;
        }

        return v;
        
    }
};