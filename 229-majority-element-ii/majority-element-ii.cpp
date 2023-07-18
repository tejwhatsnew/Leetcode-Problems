#include <bits/stdc++.h>
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int cnt1 = 0, cnt2 = 0, ele1, ele2;
        for(int i = 0; i < nums.size(); i++)
        {
            if(cnt1 == 0 && ele2 != nums[i])
            {
                cnt1 = 1;
                ele1 = nums[i];
            }
            else if(cnt2 == 0 && ele1 != nums[i])
            {
                cnt2 = 1;
                ele2 = nums[i];
            }
            else if(nums[i] == ele1) cnt1++;
            else if(nums[i] == ele2) cnt2++;
            else
            {
                cnt1--;
                cnt2--;
            }
        }

        cnt1 = 0;
        cnt2 = 0;

        int mini = int(nums.size()/3) + 1;

        vector<int> list;

        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] == ele1) cnt1++;
            if(nums[i] == ele2) cnt2++;  
        }

        if(cnt1 >= mini) list.push_back(ele1);
        if(cnt2 >= mini) list.push_back(ele2);

        sort(list.begin(), list.end());
        
        return list;
    }
};