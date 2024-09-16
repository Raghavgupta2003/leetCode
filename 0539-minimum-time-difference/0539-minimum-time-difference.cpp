// class Solution {
// public:
//     vector<string> split(string str){
//         str+=":";
//         vector<string> ans; 
//         string s="";
//         for(int i=0;i<str.size();i++){
//             if(str[i]!=':') s+=str[i];
//             else {
//                 ans.push_back(s);
//                 s="";
//             }
//         }
//         return ans;
//     }
//     int findMinDifference(vector<string>& timePoints) {
//         vector<int> ans;
//        for(int i=0;i<timePoints.size();i++){
//          vector<string> v = split(timePoints[i]);
//          if(v[0]=="00") v[0]="24";
//          int min = stoi(v[0])*60 + stoi(v[1]);
//          ans.push_back(min);
//        }
//        sort(ans.begin(),ans.end());
//        for(int i=0;i<ans.size()-1;i++){
//             ans[i]=ans[i+1]-ans[i];
//        }
//        sort(ans.begin(),ans.end());
//        for(int i=0;i<ans.size();i++){
//             cout<<ans[i]<<" ";
//        }
//        return ans[0];
//     }
// };

class Solution {
public:
    int findMinDifference(vector<string>& timepoints) {
       vector<int> ans;
       for(int i=0;i<timepoints.size();i++){
         string hour = (timepoints[i]).substr(0,2);
         if(hour=="00") hour="24";
         string min_ = (timepoints[i]).substr(3);
         int ttlmin = stoi(hour)*60 + stoi(min_);
         ans.push_back(ttlmin);
       }
       sort(ans.begin(),ans.end());
       int basecase = abs((ans[ans.size()-1]-ans[0]) - 24*60);
       for(int i=0;i<ans.size()-1;i++){
            ans[i]=ans[i+1]-ans[i];
       }
       sort(ans.begin(),ans.end());
       return min(basecase,ans[0]);
    }
};