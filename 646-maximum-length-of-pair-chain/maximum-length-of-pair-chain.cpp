class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        if(pairs.empty()) return 0;
        int count = 1;
        sort(pairs.begin(), pairs.end());

        int in = 0;
        for(int i = 1; i < pairs.size(); i++)
        {
            if(pairs[i][0] > pairs[in][1])
            {
                count++;
                in = i;
            }else if (pairs[i][1] < pairs[in][1]) {
                in = i; 
            }
        }

        return count;
    }
};