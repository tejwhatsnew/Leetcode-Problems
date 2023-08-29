class Solution {
public:
    int bestClosingTime(string customers) {
        int s = customers.size();
        vector<int> y,n;
        y.push_back(0);
        n.push_back(0);
        int count = 0;

        for(int i = 0; i < s; i++)
        {
            if(customers[i] == 'N') count++;
            n.push_back(count);
        }

        count = 0;

        for(int i = s-1; i >= 0; i--)
        {
            if(customers[i] == 'Y') count++;
            y.push_back(count);
        }
        reverse(y.begin(), y.end());
        
        int res = INT_MAX, hour = 0;
        for(int i = 0; i < s + 1; i++)
        {
            int h = y[i] + n[i];
            if(h < res)
            {
                res = h;
                hour = i;
            }
        }

        return hour;
    }
};