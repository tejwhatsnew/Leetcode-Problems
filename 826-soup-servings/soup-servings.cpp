class Solution {
public:
    vector<pair<int,int>> serves = {{100,0}, {75,25}, {50,50}, {25,75}};
    vector<vector<double>> dummy;
    double solve(double A, double B)
    {
        if(A <= 0 && B<= 0)
            return 0.5;
        
        if(A <= 0)
            return 1;
        
        if(B <= 0)
            return 0;
        
        if(dummy[A][B] != -1.0)
            return dummy[A][B];
        
        double pro = 0.0;

        for(auto p : serves)
        {
            int A_token = p.first;
            int B_token = p.second;

            pro += solve(A - A_token, B - B_token);
        }

        return dummy[A][B] = 0.25 * pro;
    }
    double soupServings(int n) {

        if(n >= 4800)
            return 1;

        dummy.resize(n+1, vector<double>(n+1, -1.0));
        return solve(n, n);
    }
};