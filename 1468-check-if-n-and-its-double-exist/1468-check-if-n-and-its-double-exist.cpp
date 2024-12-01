class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        // for(int i=0;i<arr.size();i++){
        //     for(int j=i+1;j<arr.size();j++){
        //         if(arr[i] == 2*arr[j]  || arr[j] == 2*arr[i]) return true;
        //     }
        // }
        // return false;

        //------we can check while insering in set -----------

        unordered_set<int> s;
        for(int i=0;i<arr.size();i++){
            if(s.find(2*arr[i])!=s.end()  || (arr[i]%2==0  && s.find(arr[i]/2)!=s.end())){
                return true;
            }
            s.insert(arr[i]);
        }
        
        return false;
    }
};