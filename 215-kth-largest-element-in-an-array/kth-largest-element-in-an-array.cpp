class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size()-1;
        if(n == 0) return nums[0];

        sort(nums.begin(), nums.end());
        n = n - k + 1;
        return nums[n];

        // priority_queue<int, vector<int>, greater<int>> minHeap; 
    
        // for (int num : nums) {
        //     minHeap.push(num);
        //     if (minHeap.size() > k) {
        //         minHeap.pop(); 
        //     }
        // }
        
        // return minHeap.top();
    }
};