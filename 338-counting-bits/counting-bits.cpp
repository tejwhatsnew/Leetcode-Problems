class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n+1);
        for(int i = 1; i <= n; i++)
        {
            // int temp = i, add = 0;
            // while(temp != 0)
            // {
            //     add += temp % 2;
            //     temp = temp / 2;
            // }
            // ans.push_back(add);
            ans[i] = ans[i >> 1] + (i & 1);
        }

        return ans;
    }
};