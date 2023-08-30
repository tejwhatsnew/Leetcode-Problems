class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        long long operation = 0; 
        int last = nums.back();

        for(int i = nums.size() - 2; i >= 0; i--)
        {
            int a = (nums[i] - 1) / last;
            operation += a;
            last = nums[i] / (a+1);
        }

        return operation;
    }
};