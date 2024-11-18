// class Solution {
// public:
//     vector<int> decrypt(vector<int>& code, int k) {
//         vector<int> v;
//         if(k==0){
//             for(int i=0;i<code.size();i++){
//                 v.push_back(0);
//             }
//         }
//         else if(k>0){
//             for(int i=0;i<code.size()-k;i++){
//                 int sum = 0;
//                 for(int j=1;j<=k;j++){
//                     sum+=code[i+j];
//                 }
//                 v.push_back(sum);
//             }
//             vector<int> helper;
//             for(int i=code.size()-k;i<code.size();i++){
//                helper.push_back(code[i]);
//             }
//             for(int i=0;i<code.size();i++){
//                helper.push_back(code[i]);
//             }

//             for(int i=0;i<helper.size();i++){
//                cout<<helper[i]<<" ";
//             }
         
//             for(int i=0;i<helper.size()-k;i++){
//                 int sum = 0;
//                 for(int j=1;j<=k;j++){
//                     sum+=helper[i+j];
//                 }
//                 v.push_back(sum);
//                 if(v.size()==code.size()) break;
//             }
//         }
//         else if(k<0){
//             reverse(code.begin(),code.end());
//             k = abs(k);
//              for(int i=0;i<code.size()-k;i++){
//                 int sum = 0;
//                 for(int j=1;j<=k;j++){
//                     sum+=code[i+j];
//                 }
//                 v.push_back(sum);
//             }
//             vector<int> helper;
//             for(int i=code.size()-k;i<code.size();i++){
//                helper.push_back(code[i]);
//             }
//             for(int i=0;i<code.size();i++){
//                helper.push_back(code[i]);
//             }

//             for(int i=0;i<helper.size();i++){
//                cout<<helper[i]<<" ";
//             }
         
//             for(int i=0;i<helper.size()-k;i++){
//                 int sum = 0;
//                 for(int j=1;j<=k;j++){
//                     sum+=helper[i+j];
//                 }
//                 v.push_back(sum);
//                 if(v.size()==code.size()) break;
//             }
//             reverse(v.begin(),v.end());
//         }

//         return v;
//     }
// };


//--------when we need to use previous elements----then use %---------------
// n = code.size()
// sum+=code[j%n];
// j is last "k" indexes of array 
class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        vector<int> v;
        int n = code.size();
        if(k==0){
            for(int i=0;i<code.size();i++){
                v.push_back(0);
            }
        }
        else if(k>0){
            for(int i=0;i<code.size();i++){
                int sum = 0;
                for(int j=i+1;j<=i+k;j++){
                    sum+=code[j%n];
                }
                v.push_back(sum);
            }
        }
        else if(k<0){
            reverse(code.begin(),code.end());
            k = abs(k);
             for(int i=0;i<code.size();i++){
                int sum = 0;
                for(int j=i+1;j<=i+k;j++){
                    sum+=code[j%n];
                }
                v.push_back(sum);
            }
            reverse(v.begin(),v.end());
        }

        return v;
    }
};