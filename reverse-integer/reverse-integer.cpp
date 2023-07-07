class Solution {
public:
    int reverse(int x) {
        long i = 0;
        bool flag = false;
        long y = x;
        if(x < 0)
        {
            flag = true;
            y = -y;
        }
        while(y != 0)
        {
            int r = y % 10;
            i = i*10+r;
            y = y/10;
        }
        if(i > INT_MAX || i < INT_MIN)
        {
            return 0;
        }
        if(flag)
        {
            return -(int)i;
        }
        else
        {
            return (int)i;
        }
    }
};