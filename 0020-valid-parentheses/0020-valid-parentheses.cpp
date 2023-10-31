class Solution
{
public:
    bool isValid(std::string s) 
    {
        std::vector<char> stack(s.length());
        int top = -1;

        for (const char c : s)
        {
            if (c == '{' || c == '(' || c == '[')
            {
                stack[++top] = c;
            }
            else
            {
                if (c == '}')
                {
                    if (top == -1 || stack[top] != '{')
                        return false;
                }
                if (c == ']')
                {
                    if (top == -1 || stack[top] != '[')
                        return false;
                }
                if (c == ')')
                {
                    if (top == -1 || stack[top] != '(')
                        return false;
                }
                top--;
            }
        }
        if (top != -1)
            return false;
        return true;
    }
};