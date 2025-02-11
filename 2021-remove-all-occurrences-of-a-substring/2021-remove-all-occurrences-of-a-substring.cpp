// class Solution {
// public:
//     string removeOccurrences(string s, string part) {
//         stack<char> st;
//         int n = part.size();
//         for(int i=0; i<s.size();i++){ 
//             if((st.size()>0) && (st.top() == part[n-1])){
//                 if(st.size()>=part.size()){
//                     string x ="";
//                     int num = n;
//                     while(num>0){
//                         x = st.top() + x;
//                         num--;
//                         st.pop();
//                     }
//                     cout<<x<<" ";
//                     if(x!=part){
//                         cout<<" -----"<<x<<"------  ";
//                         for(int i=0; i<x.size();i++){
//                             st.push(x[i]);
//                         }
//                     }
//                 }
//             }

//             st.push(s[i]);
//         }
//         if((st.size()>0) && (st.top() == part[n-1])){
//                 if(st.size()>=part.size()){
//                     string x ="";
//                     int num = n;
//                     while(num>0){
//                         x = st.top() + x;
//                         num--;
//                         st.pop();
//                     }
//                     cout<<x<<" ";
//                     if(x!=part){
//                         cout<<" -----"<<x<<"------  ";
//                         for(int i=0; i<x.size();i++){
//                             st.push(x[i]);
//                         }
//                     }
//                 }
//             }
//         string str = "";
//         while(st.size()>0){
//             str = (st.top()) + str;
//             st.pop();
//          }
//         return str;
//     }
// };


class Solution {
public:
    string removeOccurrences(string s, string part) {
       while(s.find(part) != string::npos){
        s.erase(s.find(part),part.size());
       }
       return s;
    }
};