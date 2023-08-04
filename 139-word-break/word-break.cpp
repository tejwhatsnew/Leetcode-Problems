class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        int n = s.length();
        
        // dp[i] represents whether the substring from index 0 to i-1 can be segmented
        vector<bool> dp(n + 1, false);
        dp[0] = true; // Empty string can always be segmented
        
        for (int i = 1; i <= n; ++i) {
            for (int j = i - 1; j >= 0; --j) {
                if (dp[j] && wordSet.find(s.substr(j, i - j)) != wordSet.end()) {
                    dp[i] = true;
                    break;
                }
            }
        }
        
        return dp[n];
    }
};