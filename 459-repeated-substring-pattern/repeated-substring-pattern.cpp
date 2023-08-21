class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.size();

        for(int i = 1; i <= n/2; i++)
        {
            if(n % i == 0)
            {
                string pattern = s.substr(0, i);
                string check = "";
                int j = n / i;

                while(j--)
                    check += pattern;
                
                if(check == s) return true;
            }
        }
        return false;
    }
};