class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // vector<vector<int>> ans;
        // sort(nums.begin(), nums.end());
        
        // for(int i = 0; i < nums.size() - 2; i++)
        // {
        //     if(i > 0 && nums[i] == nums[i - 1]) 
        //         continue;
            
        //     int j = i + 1;
        //     int k = nums.size() - 1;
        //     while(j < k)
        //     {
        //         int sum = nums[i] + nums[j] + nums[k];
        //         if(sum < 0)
        //         {
        //             j++;
        //         }
        //         else if(sum > 0)
        //         {
        //             k--;
        //         }
        //         else
        //         {
        //             ans.push_back({nums[i], nums[j], nums[k]});
        //             j++;
        //             k--;
        //             while(j < k && nums[j] == nums[j + 1]) j++;
        //             while(j < k && nums[k] == nums[k - 1]) k--;
        //         }
        //     }
            
        // }   
        // return ans;

        vector<vector<int>> triplets;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size() - 2; i++) {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            int left = i + 1;
            int right = nums.size() - 1;

            while (left < right) {
                int total_sum = nums[i] + nums[left] + nums[right];

                if (total_sum < 0) {
                    left++;
                } else if (total_sum > 0) {
                    right--;
                } else {
                    triplets.push_back({nums[i], nums[left], nums[right]});

                    // Skip duplicate elements
                    while (left < right && nums[left] == nums[left + 1])
                        left++;
                    while (left < right && nums[right] == nums[right - 1])
                        right--;

                    left++;
                    right--;
                }
            }
        }

        return triplets;

    }
};