class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        int mini = 0, maxi = 0, tap = 0;

        while(maxi < n)
        {
            for(int i = 0; i < ranges.size(); i++)
            {
                if(i - ranges[i] <= mini && i + ranges[i] >= maxi) maxi = i + ranges[i];
            }
            tap++;
            if(mini == maxi) 
            {
                return -1;
            }
            mini = maxi;
        }   

        return tap;
    }
};