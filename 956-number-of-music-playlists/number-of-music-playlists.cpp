class Solution {
private:
    const int MOD = 1e9 + 7;
    long long solution(int n, int goal, int k, vector<vector<int>>& dp)
    {
        if (n == 0 && goal == 0) return 1;
        if (n == 0 || goal == 0) return 0;
        if (dp[n][goal] != -1) return dp[n][goal];
        long long pick = solution(n - 1, goal - 1, k, dp) * n;
        long long notpick = solution(n, goal - 1, k, dp) * max(n - k, 0);
        return dp[n][goal] = (pick + notpick) % MOD;
    }
public:

    int numMusicPlaylists(int n, int goal, int k) {
        vector<vector<int>> dp(n + 1, vector<int>(goal + 1, -1));

        return solution(n, goal, k, dp);
        
    }
};