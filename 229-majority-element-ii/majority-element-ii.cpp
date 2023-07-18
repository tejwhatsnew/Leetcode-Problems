class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> list;

        for(int i = 0; i < nums.size(); i++)
        {
            int cnt = 0;
            if(list.size() == 0 || list[0] != nums[i])
            {
                for(int j = 0; j < nums.size(); j++)
                {
                    if(nums[i] == nums[j])
                        cnt++;
                }

                if(cnt > (nums.size()/3))
                    list.push_back(nums[i]);

                if(list.size() == 2) break;
            }
        }

        return list;
    }
};