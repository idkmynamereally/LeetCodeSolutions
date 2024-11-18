class Solution
{
public:
    string removeOuterParentheses(string s)
    {
        stack<char> st;
        int n = s.size();
        string ans = "";

        for (int i = 0; i < n; i++)
        {
            char c = s[i];
            if (c == '(')
            {
                if (!st.empty())
                    ans.push_back(c);
                st.push('(');
            }
            else if (c == ')')
            {
                st.pop();
                if (!st.empty())
                    ans.push_back(c);
            }
        }
        return ans;
    }
};