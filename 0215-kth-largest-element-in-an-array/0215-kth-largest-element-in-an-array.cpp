class Solution {
public:
    // Can we solve it by min heap
    // I will delete all the top(max element than the required one)
    // then top is our answer
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> minheap;

        for(int i=0; i<nums.size(); i++){
            minheap.push(nums[i]);
        }
        
        while(minheap.size() > k){
            minheap.pop();
        }

        return minheap.top();
    }
};