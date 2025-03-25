class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> result;
        result.push_back(intervals[0]);

        // if(end of first > start of second  means overlap)
         for(int i=1; i<intervals.size(); i++){
            int start = intervals[i][0];
            int end = intervals[i][1];

            if(result.back()[1] >= start){
                int newstart = min(result.back()[0], start);
                int newend = max(result.back()[1], end);

                // result.push_back({newstart, newend});  // we cannot push_back instead of it, we have to update result.back()

                result.back() = {newstart, newend};
            }else{
                result.push_back({start, end});
            }
         }
        return result;
    }
};