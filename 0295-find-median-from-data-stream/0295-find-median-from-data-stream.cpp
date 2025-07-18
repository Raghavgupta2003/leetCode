// class MedianFinder {
// public:
//     vector<int> nums;
//     MedianFinder() {
        
//     }
    
//     void addNum(int num) {
//         nums.push_back(num);
//         sort(nums.begin(), nums.end());
//     }
    
//     double findMedian() {
//         if(nums.size() == 1) return nums[0];
//         else if(nums.size() % 2 !=0) return nums[nums.size()/2];
//         else
//         return (nums[nums.size()/2 -1] + nums[nums.size()/2]) /2.0;
//     }
// };


//----Approach: we will try to use 2 heaps max and mean------------
// we will always try to maintain maxheap.size() == minHeap.size()
// Or maxheap.size() == minHeap.size() + 1
// if in any case we do not follow this condition we simply balances the tree by removing from one and pushing that in other.
class MedianFinder {
public:
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(maxHeap.size() == 0 || num <= maxHeap.top()){
            maxHeap.push(num);
        }else{
            minHeap.push(num);
        }


        //balance treee

        if(maxHeap.size() > minHeap.size() + 1){
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
        if (minHeap.size() > maxHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }
    
    double findMedian() {
        if(maxHeap.size() == minHeap.size())
        return (maxHeap.top() + minHeap.top())/2.0;

        else
        return maxHeap.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */