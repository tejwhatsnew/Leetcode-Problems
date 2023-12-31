class Solution {
private:
    bool helpMe(string s1, string s2, string s3, int i, int j, int k, vector<vector<int>> &m)
    {
        if(m[i][j] != -1) return m[i][j];

        if(i == s1.length() && j == s2.length() && k == s3.length()) return true;

        bool x = false, y = false;

        if(i < s1.length())
        {
            if(s1[i] == s3[k]) x = helpMe(s1, s2, s3, i+1, j, k+1, m);
        }

        if(j < s2.length())
        {
            if(s2[j] == s3[k]) y = helpMe(s1, s2, s3, i, j+1, k+1, m);
        }

        return m[i][j] = x||y;
    }
public:
    bool isInterleave(string s1, string s2, string s3) {
        int i = s1.size() + 1, j = s2.size() + 1;
        vector<vector<int>> m(i, vector<int>(j, -1));

        return helpMe(s1, s2, s3, 0, 0, 0, m);
    }
};