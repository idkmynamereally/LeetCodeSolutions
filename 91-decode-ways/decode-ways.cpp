class Solution
{
public:
    int numDecodings(string s)
    {
        vector<int> ways(s.size() + 1, 0);
        ways[s.size()] = 1;

        for (int i = s.size() - 1; i >= 0; i--)
        {
            decodingForIndex(s, ways, i);
        }
        return ways[0];
    }

    void decodingForIndex(string_view s, vector<int>& ways, int currIndex)
    {
        for (int j = currIndex; j < s.size(); j++)
        {
            int num = stoi(string(s.substr(currIndex, (j - currIndex + 1))));
            if (num > 0 && num < 27)
            {
                ways[currIndex] = ways[currIndex] + ways[j + 1];
            }
            else
                return;
        }
    }
};