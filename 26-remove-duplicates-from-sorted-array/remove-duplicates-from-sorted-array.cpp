class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // int expectedIndex = 1;
        // for(int i = 1; i < nums.size(); i++)
        // {
        //     if(nums[i]!=nums[i-1])
        //     {
        //         nums[expectedIndex]=nums[i];
        //         expectedIndex++;
        //     }
        // }

        set<int> res;
        for(int x : nums)
            res.insert(x);
        
        int expectedIndex = res.size();
        int j = 0;

        for(int x : res)
            nums[j++] = x;
        
        
        return expectedIndex;
    }
};
