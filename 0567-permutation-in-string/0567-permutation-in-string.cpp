class Solution {
public:
    bool check(unordered_map<char,int> m1,string str){
        for(int i=0;i<str.size();i++){
            if(m1.find(str[i])!=m1.end()){
                m1[str[i]]--;
                if(m1[str[i]]==0) m1.erase(str[i]);
            }
            else{
                return false;
            }
        }
        if(m1.size()==0) return true;
        else return false;
    }

    bool checkInclusion(string s1, string s2) 
    {   
        if(s2.size()<s1.size()) return false;
        unordered_map<char,int> m1;
        for(int i=0;i<s1.size();i++){
            m1[s1[i]]++;
        }
//**i<s2.size()-s1.size()** -> ***dont use*** create problem in testcases like  s2<s1 in size
// still we want use it to avoid TLE in testcase "bc" and "ad" then we should use
// base case *** if(s2.size()<s1.size()) return false***
        for(int i=0;i<s2.size()-s1.size()+1;i++){
            string str = s2.substr(i,s1.size());//parameter2 is length of substr;
            if(check(m1,str) == true){
                return true;
            }
        }
        return false;
    }
};