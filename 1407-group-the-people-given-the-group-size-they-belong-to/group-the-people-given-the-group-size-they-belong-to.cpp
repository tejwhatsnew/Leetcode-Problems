class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        int n = groupSizes.size();
        unordered_map<int, vector<int>> groups;
        vector<vector<int>> result;
        
        for (int i = 0; i < n; i++) {
            int groupSize = groupSizes[i];
            groups[groupSize].push_back(i);
            
            if (groups[groupSize].size() == groupSize) {
                result.push_back(groups[groupSize]);
                groups[groupSize].clear();
            }
        }
        
        for (auto& pair : groups) {
            if (!pair.second.empty()) {
                result.push_back(pair.second);
            }
        }
        
        return result;
    }
};