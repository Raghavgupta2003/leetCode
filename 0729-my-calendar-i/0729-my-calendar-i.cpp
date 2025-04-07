class MyCalendar {
public:
    vector<pair<int, int>> overlap;
    MyCalendar() {
        
    }
    bool book(int startTime, int endTime) {
        for(int i=0; i<overlap.size(); i++){
            int preS = overlap[i].first;
            int preE = overlap[i].second;

            if(max(preS, startTime) < min(preE, endTime)){ //overlap comndition
                // 10---------20
                //       15----------25
                //if(maximum of starts lies before minimum of end) -> overlap condition
                return false;
            }
        }
        overlap.push_back({startTime, endTime});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(startTime,endTime);
 */