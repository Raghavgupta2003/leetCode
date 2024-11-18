class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        vector<int> v;
        if(k==0){
            for(int i=0;i<code.size();i++){
                v.push_back(0);
            }
        }
        else if(k>0){
            for(int i=0;i<code.size()-k;i++){
                int sum = 0;
                for(int j=1;j<=k;j++){
                    sum+=code[i+j];
                }
                v.push_back(sum);
            }
            vector<int> helper;
            for(int i=code.size()-k;i<code.size();i++){
               helper.push_back(code[i]);
            }
            for(int i=0;i<code.size();i++){
               helper.push_back(code[i]);
            }

            for(int i=0;i<helper.size();i++){
               cout<<helper[i]<<" ";
            }
         
            for(int i=0;i<helper.size()-k;i++){
                int sum = 0;
                for(int j=1;j<=k;j++){
                    sum+=helper[i+j];
                }
                v.push_back(sum);
                if(v.size()==code.size()) break;
            }
        }
        else if(k<0){
            reverse(code.begin(),code.end());
            k = abs(k);
             for(int i=0;i<code.size()-k;i++){
                int sum = 0;
                for(int j=1;j<=k;j++){
                    sum+=code[i+j];
                }
                v.push_back(sum);
            }
            vector<int> helper;
            for(int i=code.size()-k;i<code.size();i++){
               helper.push_back(code[i]);
            }
            for(int i=0;i<code.size();i++){
               helper.push_back(code[i]);
            }

            for(int i=0;i<helper.size();i++){
               cout<<helper[i]<<" ";
            }
         
            for(int i=0;i<helper.size()-k;i++){
                int sum = 0;
                for(int j=1;j<=k;j++){
                    sum+=helper[i+j];
                }
                v.push_back(sum);
                if(v.size()==code.size()) break;
            }
            reverse(v.begin(),v.end());
        }

        return v;
    }
};