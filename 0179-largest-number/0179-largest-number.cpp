class Solution {
public:
    static bool myComparator(string &a, string &b){
            if(a+b>b+a) return true;
            else return false;
    }
    string largestNumber(vector<int>& nums) {
        vector<string> num;
        for(int i=0;i<nums.size();i++){
            num.push_back(to_string(nums[i]));
        }
        
        sort(num.begin(),num.end(),myComparator);
        string ans="";
        for(int i=0;i<nums.size();i++){
            ans+=num[i];
        }
        if(num[0]=="0") return "0";
        return ans;
    }
};