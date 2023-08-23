class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char, int> freq;

        for(char c : s) freq[c]++;

        priority_queue<pair<int, char>> q;

        for(auto i : freq) q.push(make_pair(i.second, i.first));

        pair<char, int> b ={-1, '$'};

        string ans = "";



        while(!q.empty())
        {
            auto temp = q.top();
            q.pop();
            
            if(!ans.empty() && ans.back() == temp.second)
            {
                if(q.empty()) return "";
                auto next = q.top();
                q.pop();
                ans += next.second;
                next.first--;
                if(next.first > 0) q.push(next);
                q.push(temp);
            }
            else
            {
                ans += temp.second;
                temp.first--;
                if(temp.first > 0) q.push(temp);
            }
        }
        return ans;
    }
};