class Solution 
{
public:
    std::vector<std::string> generateParenthesis(int n)
    {
        std::vector<std::string> ret;
        recurse(ret, 0, 0, "", n);
        return ret;
    }

    void recurse(std::vector<std::string>& ret, int leftCount, int rightCount, std::string s, int n)
    {
        if (leftCount == n && rightCount == n)
        {
            ret.push_back(s);
            return;
        }

        if (leftCount < n)
        {
            recurse(ret, leftCount + 1, rightCount, s + "(", n);
        }
        if (rightCount < leftCount)
        {
            recurse(ret, leftCount, rightCount + 1, s + ")", n);
        }
    }
};