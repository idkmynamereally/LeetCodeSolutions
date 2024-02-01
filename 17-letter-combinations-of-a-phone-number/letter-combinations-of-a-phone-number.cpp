class Solution {
public:
    vector<string> letterCombinations(string digits) 
    {
        vector<string> ans;
        if (digits.size() == 0)
            return ans;
        string curr;
        vector<string> phone{"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        helper(ans, curr, 0, phone, digits);
        return ans;
    }

    void helper(vector<string>& ans, string& curr, int currIndex, vector<string>& phone, string_view digits)
    {
        if (currIndex == digits.size())
        {
            ans.push_back(curr);
            return;
        }

        string chars = phone[digits.at(currIndex) - '0' - 2];
        for (char c : chars)
        {
            curr.push_back(c);
            helper(ans, curr, currIndex + 1, phone, digits);
            curr.pop_back();
        }
    }
};