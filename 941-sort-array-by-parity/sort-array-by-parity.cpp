class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        vector<int> ans(nums.size());
        int n = nums.size();
        int m = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i]%2 == 0)
            {
                ans[m++] =nums[i];
            }
            else
            {
                ans[--n] = nums[i];
            }
        }

        return ans;
    }
};