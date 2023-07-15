class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int missing = -1;

        for(int i = 0; i < nums.size()+1; i++)
        {
           if(count(nums.begin(), nums.end(), i) == 0)
           {
               missing = i;
               break;
           }
        }
        return missing;
    }
};