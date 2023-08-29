class Solution {
public:
    int bestClosingTime(string customers) {
        int hour = 0, count = 0;

        for(int i = 0; i < customers.length(); i++)
        {
            if(customers[i] == 'Y')
            {
                count++;

                if(count > 0)
                {
                    hour = i + 1;
                    count = 0;
                }
            }
            else
                count--;
        }

        return hour;
    }
};