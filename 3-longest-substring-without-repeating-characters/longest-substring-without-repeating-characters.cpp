class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size() == 0) return 0;
        int count = 0;
        unordered_set<int>set;
        int l = 0;
        for(int r = 0; r < s.length(); r++)
        {
            if(set.find(s[r]) != set.end())
            {
                while(l < r && set.find(s[r]) != set.end())
                {
                    set.erase(s[l]);
                    l++;
                }
            }
            set.insert(s[r]);
            count = max(count, r - l + 1);
        }
        return count;
    }
};