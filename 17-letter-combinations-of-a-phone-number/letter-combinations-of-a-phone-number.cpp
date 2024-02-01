class Solution {
public:
    vector<string> letterCombinations(string digits) 
    {
        vector<string> ans;
        if (digits.size() == 0)
            return ans;
        string curr;
        unordered_map<char, string> phone;
        string arr[8]{"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        char c = '1';
        for (int i = 0; i < 8; i++)
        {
            c++;
            phone[c] = arr[i];
        }
        helper(ans, curr, 0, phone, digits);
        return ans;
    }

    void helper(vector<string>& ans, string& curr, int currIndex, unordered_map<char, string>& phone, string_view digits)
    {
        if (currIndex == digits.size())
        {
            ans.push_back(curr);
            return;
        }

        string chars = phone[digits.at(currIndex)];
        for (char c : chars)
        {
            curr.push_back(c);
            helper(ans, curr, currIndex + 1, phone, digits);
            curr.pop_back();
        }
    }
};