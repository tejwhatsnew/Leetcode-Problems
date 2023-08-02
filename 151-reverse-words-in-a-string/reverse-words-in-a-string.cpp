class Solution {
public:
    string reverseWords(string s) {
        int left=0;
        int right = s.length() - 1;

        string ans = "", temp = "";

        while(s[left] == ' ') left++;

        while(s[right] == ' ') right--;

        while(left <= right)
        {
            if(s[left] != ' ') temp += s[left];
            else
            {
                if(s[left-1] == ' ')
                {
                    left++;
                    continue;
                }
                else
                {
                    ans = temp + " " + ans;
                    temp = "";
                }
            }
            left++;
        }
        ans = temp + " " + ans;
        ans.erase(ans.begin() + ans.length() - 1); // to remove the extra space at the end
        return ans;
    }
};