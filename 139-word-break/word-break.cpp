class Solution {
private:
    // bool helpWB(string s, unordered_set<string>& st, int i, vector<bool>& dp)
    // {
    //     if(i == s.size()) return true;

    //     if(dp[i] != false) return dp[i];

    //     string temp;

    //     for(int j = i; j < s.length(); j++)
    //     {
    //         temp += s[j];

    //         if(st.find(temp) != st.end())
    //         {
    //             if(helpWB(s, st, j+1, dp)) 
    //             {
    //                 return dp[i] = true;
    //                 break;
    //             }
    //         }
    //     }

    //     return dp[i] = false;
    // }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st;
        for(auto i : wordDict) st.insert(i);
        vector<bool> dp(s.size() + 1, false);
        dp[0] = true;
        for (int i = 1; i <= s.length(); ++i) {
            for (int j = i - 1; j >= 0; --j) {
                if (dp[j] && st.find(s.substr(j, i - j)) != st.end()) {
                    dp[i] = true;
                    break;
                }
            }
        }
        
        return dp[s.length()];
        // return helpWB(s, st, 0, dp);
    }
};