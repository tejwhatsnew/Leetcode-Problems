class Solution {
public:
    void backtrack(vector<std::vector<int>>& combinations, vector<int>& current_combination, int start, int n, int k) {
        if (k == 0) {
            combinations.push_back(current_combination);
            return;
        }

        for (int i = start; i <= n; ++i) {
            current_combination.push_back(i);
            backtrack(combinations, current_combination, i + 1, n, k - 1);
            current_combination.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> com;

         backtrack(res, com, 1, n, k);

        return res;
    }
};