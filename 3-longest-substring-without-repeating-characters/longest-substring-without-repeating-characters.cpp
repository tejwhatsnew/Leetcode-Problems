class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size() == 0) return 0;
        int count = 0;
        unordered_map<char,int>umap;
        int l = 0, r = 0;
        while(r < s.length())
        {
            if(umap.find(s[r]) != umap.end()) l = max(umap[s[r]] + 1, l);

            umap[s[r]] = r;

            count = max(count, r - l + 1);
            r++;
        }
        return count;
    }
};