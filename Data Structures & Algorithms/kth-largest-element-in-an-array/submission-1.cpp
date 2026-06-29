class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int>max_heap;
        for( int num : nums){
            max_heap.push(num);
        }
        int kth=0;
        while(max_heap.size()>=0){
            kth=max_heap.top();
            max_heap.pop();
            k--;
            if(k==0){
                break;
            }
        }
        return kth;
    }
};
