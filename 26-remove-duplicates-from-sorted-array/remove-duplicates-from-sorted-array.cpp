class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0;
        int j = 1;
        while(j < nums.size())
        {
            if(nums[i] != nums[j])
            {
                i++;
                nums[i] = nums[j];
            }
            else j++;
        }
        return i+1;
        // int expectedIndex = 1;
        // for(int i = 1; i < nums.size(); i++)
        // {
        //     if(nums[i]!=nums[i-1])
        //     {
        //         nums[expectedIndex]=nums[i];
        //         expectedIndex++;
        //     }
        // }

        // set<int> res;
        // for(int x : nums)
        //     res.insert(x);
        
        // int expectedIndex = res.size();
        // int j = 0;

        // for(int x : res)
        //     nums[j++] = x;
        // return expectedIndex;
    }
};
