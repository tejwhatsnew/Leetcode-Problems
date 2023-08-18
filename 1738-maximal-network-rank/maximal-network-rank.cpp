class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<int> connectedCount(n, 0);

        // Count the number of connected roads for each city
        for (const auto& road : roads) {
            connectedCount[road[0]]++;
            connectedCount[road[1]]++;
        }

        int maxRank = 0;

        // Calculate the network rank for each pair of cities
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int networkRank = connectedCount[i] + connectedCount[j];

                // If there's a direct road between the cities, decrement networkRank
                for (const auto& road : roads) {
                    if ((road[0] == i && road[1] == j) || (road[0] == j && road[1] == i)) {
                        networkRank--;
                        break;
                    }
                }

                maxRank = max(maxRank, networkRank);
            }
        }

        return maxRank;
    }
};