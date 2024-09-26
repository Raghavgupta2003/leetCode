class MyCalendar {
public:
    vector<pair<int,int>> v;
   
    MyCalendar() {
        v.push_back({0,0});
    }
    bool book(int start, int end) {
        for(int i=0;i<v.size();i++){
           pair<int,int> pre = v[i];
           if((min(pre.first,pre.second) < max(start,end)) &&  (max(pre.first,pre.second)>min(start,end))){
                return false;
           }
        }
        v.push_back({start,end});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */