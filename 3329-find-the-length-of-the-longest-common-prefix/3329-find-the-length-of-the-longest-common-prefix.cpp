class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        vector<string> array1;
        vector<string> array2;
        for(int i=0;i<arr1.size();i++){
           array1.push_back(to_string(arr1[i]));
        }
        for(int i=0;i<arr2.size();i++){
           array2.push_back(to_string(arr2[i]));
        }
        // int max=0;
        // for(int i=0;i<array1.size();i++){
        //     for(int j=0;j<array2.size();j++){
        //         string s1=array1[i];
        //         string s2=array2[j];
        //         int cnt=0;
        //         // if(s1==s2) max = s1.size();
        //         for(int k=0;k<min(s1.size(),s2.size());k++){
        //             if(s1[k]==s2[k]){
        //                 cnt++;
        //             }
        //             else{
        //                 break;
        //             }
        //         }
        //         if(cnt>max) max=cnt;
        //     }
        // }

        // return max;

        set<string> s;
        for(int i=0;i<array1.size();i++){
            string ss=array1[i];
            string str="";
            for(int j=0;j<ss.size();j++){
                str+=ss[j];
                s.insert(str);
            }
        }

        int Max=0;
        for(int i=0;i<array2.size();i++){
            string ss=array2[i];
            string str="";
            for(int j=0;j<ss.size();j++){
                str+=ss[j];
                if(s.find(str)!=s.end()){
                    // Max = max(Max,str.size());
                    if(Max<=str.size()) Max=str.size();
                }
            }
        }
        return Max;
    }
};