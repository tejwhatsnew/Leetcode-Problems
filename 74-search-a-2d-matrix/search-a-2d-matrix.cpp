class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), m = matrix[0].size();
        int low = 0, high = (m*n)-1;
        if(!matrix.size()) return false;
        while(low <= high)
        {
            int middle = (low + (high - low) / 2);

            if(matrix[middle / m][middle % m] == target)
            {
                return true;
            }
            if(matrix[middle / m][middle % m] < target)
            {
                low = middle + 1;
            }
            else
            {
                high = middle - 1;
            }
        }

        return false;
    }
};