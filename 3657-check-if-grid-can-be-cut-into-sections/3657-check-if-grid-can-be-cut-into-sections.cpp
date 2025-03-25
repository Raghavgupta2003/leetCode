class Solution {
public:
    vector<vector<int>> overlap(vector<vector<int>>& arr){
        sort(arr.begin(), arr.end());
        vector<vector<int>> result;
        result.push_back(arr[0]);

        for(int i=0; i<arr.size(); i++){
            int start = arr[i][0];
            int end = arr[i][1];

            int resStart = result.back()[0];
            int resEnd = result.back()[1];

            // overlap only when resultEnd > start; as we sorted the arr
            if(resEnd > start){
                result.back() = {min(resStart, start), max(resEnd, end)};
            }else{
                result.push_back({start, end});
            }
        }

        return result;
    }
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        vector<vector<int>> xAxis;
        vector<vector<int>> yAxis;
        

        // separating all x variables and y variables.
        for(int i=0; i<rectangles.size(); i++){
            int x1 = rectangles[i][0];
            int y1 = rectangles[i][1];
            int x2 = rectangles[i][2];
            int y2 = rectangles[i][3];

            xAxis.push_back({x1, x2});
            yAxis.push_back({y1, y2});
        }

        vector<vector<int>> overlapX = overlap(xAxis);
        vector<vector<int>> overlapY = overlap(yAxis);

        // for(int i=0; i<overlapX.size(); i++){
        //       cout<<overlapX[i][0]<<" "<<overlapX[i][1]<<endl;
        // }
        // cout<<endl<<endl<<endl;
        // for(int i=0; i<overlapY.size(); i++){
        //       cout<<overlapY[i][0]<<" "<<overlapY[i][1]<<endl;
        // }


//******* if any overlapped result has size greater than or equal to 3, it means we can divide the matrix by 2 lines ********
        if(overlapX.size()>=3 || overlapY.size()>=3){
            return true;
        }
        else return false;
    }
};