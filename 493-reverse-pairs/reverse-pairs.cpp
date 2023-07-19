class Solution {
public:
    void merge(vector<int>& nums, int low, int mid, int high)
    {
        vector<int> temp;
        int left = low, right = mid + 1;
        while(left <= mid && right <= high)
        {
            if(nums[left] <= nums[right])
            {
                temp.push_back(nums[left]);
                left++;
            }
            else
            {
                temp.push_back(nums[right]);
                right++;
            }
        }

        while(left <= mid)
        {
            temp.push_back(nums[left]);
            left++;
        }

        while(right <= high)
        {
            temp.push_back(nums[right]);
            right++;
        }

        for(int i = low; i <= high; i++)
        {
            nums[i] = temp[i - low];
        }

    }
    int countPairs(vector<int>& nums, int low, int mid, int high)
    {
        int count = 0;
        int right = mid + 1;
        for(int i = low; i <= mid; i++)
        {
            while(right <= high && nums[i] > 2 * (long)nums[right])
                right++;
            
            count += (right - (mid +1));
        }
        return count;
    }
    int mergeSort(vector<int>& nums, int low, int high)
    {
        int mid = (low + high) / 2;
        int count = 0;
        if(low >= high) return count;
        count += mergeSort(nums, low, mid);
        count += mergeSort(nums, mid + 1, high);
        count += countPairs(nums, low, mid, high);
        merge(nums, low, mid, high);
        return count;
    }
    int reversePairs(vector<int>& nums) {
        return  mergeSort(nums, 0, nums.size()-1);
    }
};