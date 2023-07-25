class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count = 0;
        unordered_map<int,int> umap;
        int preSum = 0;
        umap[0] = 1;

        for(int i = 0; i < nums.size(); i++)
        {
            preSum += nums[i];
            int remove = preSum - k;
            count += umap[remove];
            umap[preSum] += 1;
        }
        return count;
    }
};