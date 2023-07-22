class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        set<vector<int>> pairs;
        int n = nums.size();

        for(int  i = 0; i < n - 2; i++)
        {
            for(int j = i+1; j < n - 1; j++)
            {
                set<long long> hashset;
                for(int k = j+1; k < n; k++)
                {
                    long long sum = nums[i] + nums[j];
                    sum += nums[k];
                    long long fourth = target - (sum);
                    if(hashset.find(fourth) != hashset.end())
                    {
                        vector<int> temp = {nums[i], nums[j], nums[k], (int)fourth};
                        sort(temp.begin(), temp.end());
                        pairs.insert(temp);
                    }
                    hashset.insert(nums[k]);
                }
            }
        }

        vector<vector<int>> ans(pairs.begin(), pairs.end());
        return ans;
    }
};