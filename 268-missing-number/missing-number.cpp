class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int missing, sum = 0;
        for(int i = 0; i < nums.size(); i++) sum += nums[i];
        int n = nums.size();
        int num = (n*(n+1)) / 2;
        missing = num - sum;
        return missing;
    }
};