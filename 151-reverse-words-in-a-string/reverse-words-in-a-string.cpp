class Solution {
public:
    string reverseWords(string s) {
        stack<string> st;
        string res, word;
        for(char i : s)
        {
            if(i != ' ') word += i;
            else if(!word.empty())
            {
                st.push(word);
                word="";
            }
        }
        
        if(!word.empty()) st.push(word);

        res="";
        while(!st.empty())
        {
            res += st.top() + " ";
            st.pop();
        }
        if(!res.empty()) res.pop_back();
        return res;
    }
};