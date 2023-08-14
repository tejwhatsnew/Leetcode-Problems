class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size()-1;
        if(n == 0) return nums[0];

        sort(nums.begin(), nums.end());

        return nums[n-k+1];
    }
};