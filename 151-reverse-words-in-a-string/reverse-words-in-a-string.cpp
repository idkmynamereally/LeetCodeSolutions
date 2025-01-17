class Solution {
public:
    string reverseWords(string s) {
        stack<string> st;
        s += " ";

        for (int i = 0; i < s.size(); i++)
        {
            while (i < s.size() && s[i] == ' ')
                i++;
            if (i == s.size())
                break;
            string sr;

            while (i < s.size() && s[i] != ' ')
            {
                sr.push_back(s[i]);
                i++;
            }
            st.push(sr);
        }

        string ans = "";

        while (!st.empty())
        {
            ans += st.top();
            st.pop();

            if (!st.empty())
                ans += " ";
        }

        return ans;
    }
};