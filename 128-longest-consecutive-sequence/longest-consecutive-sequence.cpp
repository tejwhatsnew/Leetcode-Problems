class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int longest = 0;
        int lstMin = INT_MIN;
        int count = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i]-1 == lstMin)
            {
                count++;
                lstMin = nums[i];
            }
            else if(nums[i] != lstMin)
            {
                count = 1;
                lstMin = nums[i];
            }

            longest = max(count, longest);
        }
        return longest;
    }
};