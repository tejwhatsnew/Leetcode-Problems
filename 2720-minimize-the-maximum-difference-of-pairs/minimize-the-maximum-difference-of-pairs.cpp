class Solution {
private:
    bool isValid(vector<int>& nums, int mid, int p)
    {
        int n = nums.size();
        int i = 0;
        int cnt = 0;

        while(i < n-1)
        {
            if(nums[i+1] - nums[i] <= mid)
            {
                cnt++;
                i += 2;
            }
            else
                i++;
        }
        return cnt >= p;
    }
public:
    int minimizeMax(vector<int>& nums, int p) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int l = 0;
        int r = nums[n - 1] - nums[0];
        int res = INT_MAX;

        while(l <= r)
        {
            int mid = (l + r) / 2;
            if(isValid(nums, mid, p))
            {
                res = mid;
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        } 
        return res;
    }
};