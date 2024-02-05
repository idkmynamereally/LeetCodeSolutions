class Solution
{
public:
    string longestPalindrome(string s) 
    {
        string ans;
        for (int i = 0; i < s.size(); i++)
        {
            makePalindrome(s, i, ans);
        }
        return ans;
    }

    void makePalindrome(string_view s, int midIndex, string& ans)
    {
        int leftIndex = midIndex;
        int rightIndex = midIndex;
        while (leftIndex >= 0 && rightIndex < s.size())
        {
            if (s[leftIndex] != s[rightIndex])
                break;
            leftIndex--;
            rightIndex++;
        }
        leftIndex++;
        rightIndex--;
        if ((rightIndex - leftIndex + 1) > ans.size())
            ans = s.substr(leftIndex, (rightIndex - leftIndex + 1));

        
        leftIndex = midIndex;
        rightIndex = midIndex + 1;

        while (leftIndex >= 0 && rightIndex < s.size())
        {
            if (s[leftIndex] != s[rightIndex])
                break;
            leftIndex--;
            rightIndex++;
        }
        leftIndex++;
        rightIndex--;
        if ((rightIndex - leftIndex + 1) > ans.size())
            ans = s.substr(leftIndex, (rightIndex - leftIndex + 1));
    }
};