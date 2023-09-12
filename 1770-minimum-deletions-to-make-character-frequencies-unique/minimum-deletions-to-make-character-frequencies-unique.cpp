class Solution {
public:
    int minDeletions(string s) {
        unordered_map<char,int> count;
        for(char c : s)
        {
            count[c]++;
        }
        unordered_set<int> fset;
        int res = 0;
        for(auto& i : count)
        {
            int f = i.second;
            while(f > 0 && fset.count(f))
            {
                f--;
                res++;
            }
            fset.insert(f);
        }
        return res;
    }
};