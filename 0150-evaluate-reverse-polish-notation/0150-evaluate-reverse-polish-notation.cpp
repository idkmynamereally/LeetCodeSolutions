class Solution 
{
public:
    int evalRPN(std::vector<std::string>& tokens) 
    {
        std::stack<int> s;
        for (const auto& i : tokens)
        {
            int a{};
            int b{};
            if (i == "+" || i == "-" || i == "*" || i == "/")
            {
                a = s.top();
                s.pop();
                b = s.top();
                s.pop();
                if (i == "+")
                {
                    s.push(b + a);
                }
                if (i == "-")
                {
                    s.push(b - a);
                }
                if (i == "/")
                {
                    s.push(b / a);
                }
                if (i == "*")
                {
                    s.push(b * a);
                }
            }
            else
            {
                s.push(std::stoi(i));
            }
        }
        return s.top();
    }
};