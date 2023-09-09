class Solution {
// private:
//     int solve(vector<int>& nums, int target,vector<int>& dp)
//     {
//         if(target < 0) return 0;
//         if(target == 0) return 1;
//         if(dp[target] != -1) return dp[target];

//         int ans = 0;
//         for(int i = 0; i < nums.size(); i++)
//         {
//             ans += solve(nums, target-nums[i], dp);
//         }

//         return dp[target] = ans;
//     }
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<unsigned long long> dp(target+1, 0);
        dp[0] = 1;
        
        for(int i = 1; i <= target; i++)
        {
            for(int j = 0; j < nums.size(); j++)
            {
                int ans = nums[j];
                if(i - ans >= 0)
                    dp[i] += dp[i - ans];
            }
        }
        return dp[target];   
    }
};