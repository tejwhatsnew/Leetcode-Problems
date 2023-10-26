class Solution {
    const int MOD = 1e9 + 7;
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
         sort(arr.begin(), arr.end());
    int n = arr.size();
    
    unordered_map<int, long long> dp;
    
    long long total = 0;
    
    for (int i = 0; i < n; i++) {
        dp[arr[i]] = 1;
        
        for (int j = 0; j < i; j++) {
            if (arr[i] % arr[j] == 0) {
                int complement = arr[i] / arr[j];
                if (dp.count(complement)) {
                    dp[arr[i]] = (dp[arr[i]] + dp[arr[j]] * dp[complement]) % MOD;
                }
            }
        }
        
        total = (total + dp[arr[i]]) % MOD;
    }
    
    return (int)(total % MOD);
    }
};