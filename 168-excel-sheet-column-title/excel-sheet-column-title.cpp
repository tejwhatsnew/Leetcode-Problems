class Solution {
public:
    string convertToTitle(int columnNumber) {
        string res;

        while(columnNumber>0)
        {
            int reminder = columnNumber % 26;
            if(reminder == 0)
            {
                reminder = 26;
                columnNumber -= 1;
            }

            res = char('A' + reminder - 1) + res;
            columnNumber /= 26;
        }
        return res;
    }
};