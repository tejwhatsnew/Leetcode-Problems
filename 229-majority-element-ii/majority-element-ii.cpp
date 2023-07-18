#include <bits/stdc++.h>
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> list;
        map<int,int> hash;
        int mini = int(nums.size()/3) + 1;
        
        for(int i = 0; i < nums.size(); i++)
        {
            hash[nums[i]]++;

            if(hash[nums[i]] == mini)
                list.push_back(nums[i]);
            
            if(list.size() == 2) break;
        }
        return list;
    }
};