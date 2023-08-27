class Solution {
public:
    bool canCross(vector<int>& stones) {
        unordered_map<int, unordered_set<int>> mapi;

        for(int i : stones) mapi[i] = {};

        mapi[stones[0]] = {1};

        for(int i = 0; i < stones.size(); i++)
        {
            int curr = stones[i];
            unordered_set<int> jumps = mapi[curr];
            for(int jump : jumps)
            {
                int pos = curr + jump;
                if(pos == stones[stones.size() - 1]) return true;
                if(mapi.find(pos) != mapi.end())
                {
                    if(jump - 1 > 0) mapi[pos].insert(jump-1);
                    mapi[pos].insert({jump, jump + 1});
                }
            }
        }

        return false;
    }
};