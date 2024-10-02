class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> v = arr;
        sort(v.begin(),v.end());
        map<int,int> m;
        int rank=1;
        for(int i =0;i<v.size();i++){
            if(m.find(v[i])==m.end()){
                m[v[i]]=rank;
                rank++;
            }
        }

        for(int i=0;i<arr.size();i++){
            if(m.find(arr[i])!=m.end()){
                arr[i] = m[arr[i]];
            }
        }
        return arr;
    }
};