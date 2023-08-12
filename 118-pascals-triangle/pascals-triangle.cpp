class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for(int i = 1; i <= numRows; i++)
        {
            ans.push_back(giveRow(i));
        }
        return ans;
    }
    vector<int> giveRow(int row)
    {
        long long res = 1;
        vector<int> ans;
        ans.push_back(1);

        for(int  i = 1; i < row; i++)
        {
            res = res * (row - i);
            res = res / i;
            ans.push_back(res);
        }
        return ans;
    }
};