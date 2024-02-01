class Solution {
public:
    vector<vector<string>> partition(string s) 
    {
        vector<vector<string>> ans;
        vector<string> curr;
        if (!s.size())
            return ans;
        if (s.size() == 1)
        {
            curr.push_back(s.substr(0, 1));
            ans.push_back(curr);
            return ans;
        }
        for (int i = 0; i < s.size(); i++)
            helper(ans, curr, 0, i+1, s);
        return ans;
    }

    void helper(vector<vector<string>>& ans, vector<string> curr, int currIndex, int remIndex, string_view s)
    {
        string currPartString = string(s.substr(currIndex, remIndex - currIndex));
        if (isPalindrome(0, currPartString.size() - 1, currPartString))
        {
            //std::cout << currPartString << "\n";
            curr.push_back(currPartString);

            if (remIndex == s.size())
                ans.push_back(curr);

            for (int i = remIndex + 1; i <= s.size(); i++)
            {
                helper(ans, curr, remIndex, i, s);
            }
        }
    }

    bool isPalindrome(int startIndex, int endIndex, string_view s)
    {
        while (startIndex < endIndex)
        {
            if (s[startIndex] == s[endIndex])
            {
                startIndex++;
                endIndex--;
                continue;
            }
            return false;
        }
        return true;
    }
};