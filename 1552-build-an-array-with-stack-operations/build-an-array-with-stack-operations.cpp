class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        unordered_set<int> t_set(target.begin(), target.end());
        vector<string> res;

        for(int i = 1; i <= target.back(); i++)
        {
            if(t_set.find(i) != t_set.end()) res.push_back("Push");

            else{
                res.push_back("Push");
                res.push_back("Pop");
            }
        }

        return res;
    }
};