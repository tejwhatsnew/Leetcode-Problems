class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.size();

        for(int i = n/2; i > 0; i--)
        {
            if(n % i == 0)
            {
                string pattern = s.substr(0, i);
                string check = "";
                int j = n / i;

                while(j--)
                    check += pattern;
                
                if(check == s) return true;
                // bool isPattern = true;
                // for (int j = i; j < n; j++) {
                //     if (s[j] != s[j - i]) {
                //         isPattern = false;
                //         break;
                //     }
                // }
                // if (isPattern) {
                //     return true;
                // }
            }
        }
        return false;
    }
};