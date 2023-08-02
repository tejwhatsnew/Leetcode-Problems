class Solution {
public:
    void backtrack(vector<int>& nums, vector<int>& permutation, vector<vector<int>>& result) {
        if (permutation.size() == nums.size()) {
            result.push_back(permutation);
            return;
        }

        for (int num : nums) {
            if (std::find(permutation.begin(), permutation.end(), num) == permutation.end()) {
                permutation.push_back(num);
                backtrack(nums, permutation, result);
                permutation.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<std::vector<int>> result;
        vector<int> permutation;
        backtrack(nums, permutation, result);
        return result;
    }
};