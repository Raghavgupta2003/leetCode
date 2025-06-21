class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        //we maintain a window of k size at starting of arr
        //we take a element from end and decrease size of starting arr
        
        int leftSum = 0;
        int rightSum = 0;

        //leftSum = sum of starting window

        for(int i=0; i<k; i++){
            leftSum += cardPoints[i];
        }

        //we decrease window of starting and add element from end
        int MaxSum = leftSum;

        int lastIdx = n-1;
        for(int i=k-1; i>=0; i--){
            leftSum -= cardPoints[i];
            rightSum += cardPoints[lastIdx--];
            
            MaxSum = max(MaxSum, leftSum + rightSum);
        }
        return MaxSum;
    }
};