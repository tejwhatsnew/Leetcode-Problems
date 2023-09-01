class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans;
        for(int i = 0; i <= n; i++)
        {
            int temp = i, add = 0;
            while(temp != 0)
            {
                add += temp % 2;
                temp = temp / 2;
            }
            ans.push_back(add);
        }

        return ans;
    }
};