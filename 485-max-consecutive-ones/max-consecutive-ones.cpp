class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 0;
        int maxi = 0;
        for(int i : nums)
        {
            if(i == 1) ++count;
            else count = 0;

            maxi = max(count, maxi);
        }
        return maxi;
    }
};