class MyCalendarTwo {
public:
    vector<pair<int,int>> v;
    vector<pair<int,int>> overlap;
    MyCalendarTwo() {
    }

    
    bool book(int start, int end) {
        
        for(int i=0;i<overlap.size();i++){
            pair<int,int> pre = overlap[i];
            if((min(pre.first,pre.second)<max(start,end) && max(pre.first,pre.second)>min(start,end))){
                return false;
            }
        }
        for(int i=0;i<v.size();i++){
            pair<int,int> pre = v[i];
            if((min(pre.first,pre.second)<max(start,end) && max(pre.first,pre.second)>min(start,end))){
                pair<int,int> p;
                p.first = max(pre.first,start);
                p.second = min(pre.second,end);
                overlap.push_back(p);
            }
        }

        


        
        // if(arr.size()==2){
        //     pair<int,int> p1 = arr[0];
        //     pair<int,int> p2 =arr[1];

        //     pair<int,int> check1;
        //     pair<int,int> check2;

        //    check1.first = max(p1.first,start);
        //    check1.second = min(p1.second,end);

        //    check2.first = max(p2.first,start);
        //    check2.second = min(p2.second,end);

        //     if((min(check1.first,check1.second)<max(check2.first,check2.second) && max(check1.first,check1.second)>min(check2.first,check2.second))){
        //        return false;
        //     }
        // }
        
        v.push_back({start,end});
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */