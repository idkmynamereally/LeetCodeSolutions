class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for (auto s : tokens)
        {
            if (s != "/" && s != "-" && s != "+" && s != "*")
            {
                int va = 0;
                int m = 1;
                for (int i = s.size() - 1; i >= 0; i--)
                {
                    char t = s[i];
                    if (t == '-')
                    {
                        va *= -1;
                        break;
                    }
                    va += (t - '0') * m;
                    m *= 10;
                }
                st.push(va);
                continue;
            }

            int va = st.top();
            st.pop();
            int vb = st.top();
            st.pop();

            if (s == "*")
            {
                vb *= va;
                st.push(vb);
            }
            if (s == "-")
            {
                vb -= va;
                st.push(vb);
            }
            if (s == "/")
            {
                vb /= va;
                st.push(vb);
            }
            if (s == "+")
            {
                vb += va;
                st.push(vb);
            }
        }
        return st.top();
    }
};