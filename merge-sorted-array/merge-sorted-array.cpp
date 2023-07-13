class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // int left = nums1.size() - 1, right = 0;
        // while(left >= 0 and right < nums2.size())
        // {
        //         if(nums1[left] > nums2[right])
        //         {
        //             swap(nums1[left], nums2[right]);
        //             left--, right++;
        //         }
        //         else
        //             break;
            
        // }

        int i = 0;

        while(i < nums2.size())
        {
            nums1[m + i] = nums2[i];
            i++;
        }

        sort(nums1.begin(), nums1.end());
        // sort(nums2.begin(), nums2.end());
    }
};