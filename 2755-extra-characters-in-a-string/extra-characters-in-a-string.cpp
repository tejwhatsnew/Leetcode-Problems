class Solution {
private:
    int solve(string s, unordered_map<string,int>& mp, vector<int>& dp, int in)
    {
        if(in >= s.size()) return 0;
        if(dp[in] != -1) return dp[in];

        string curStr = "";
        int ans = s.size();

        for(int i = in; i < s.size(); i++)
        {
            curStr.push_back(s[i]);
            int count = (mp.count(curStr)? 0 : curStr.size()) + solve(s, mp, dp, i+1);

            ans = min(ans, count);
        }

        return dp[in] = ans;
    }
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        vector<int> dp(s.size(), -1);
        unordered_map<string,int> mapi;

        for(string word : dictionary) mapi[word]++;

        int ans = solve(s, mapi, dp, 0);

        return ans;
    }
};