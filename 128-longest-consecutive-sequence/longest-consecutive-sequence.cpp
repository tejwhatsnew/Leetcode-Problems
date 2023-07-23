class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> uset;
        int longest = 0;
        
        for(int i = 0; i < nums.size(); i++)
        {
            uset.insert(nums[i]);
        }
        for(auto i : uset)
        {
            int count = 0;
            int x = i;
            if(uset.find(x-1) == uset.end())
            {
                count = 1;
                while(uset.find(x + 1) != uset.end())
                {
                    count++;
                    x += 1;
                }
            }
            
            longest = max(longest, count);
        }
        return longest;
    }
};