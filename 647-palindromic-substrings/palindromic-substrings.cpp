class Solution
{
public:
    int countSubstrings(string s)
    {
        int ans{ 0 };
        for (int i = 0; i < s.size(); i++)
        {
            makePalindrome(s, i, ans);
        }
        return ans;
    }
    void makePalindrome(string_view s, int mid, int& count)
    {
        int start = mid;
        int end = mid;

        while (start >= 0 && end < s.size())
        {
            if (s[start] == s[end])
            {
                count++;
                start--;
                end++;
            }
            else
                break;
        }

        start = mid;
        end = mid + 1;

        while (start >= 0 && end < s.size())
        {
            if (s[start] == s[end])
            {
                start--;
                end++;
                count++;
            }
            else
                break;
        }
        return;
    }
};