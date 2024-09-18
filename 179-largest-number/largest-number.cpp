class Solution
{
public:
    string largestNumber(vector<int> &nums)
    {
        vector<string> n1;

        for (int i = 0; i < nums.size(); i++)
        {
            string s;
            if (nums[i] == 0)
            {
                n1.push_back("0");
                continue;
            }
            while (nums[i])
            {
                s += to_string(nums[i] % 10);
                nums[i] /= 10;
            }
            reverse(s.begin(), s.end());
            n1.push_back(s);
        }

        sort(n1.begin(), n1.end(), [](string s1, string s2)
            {
            if (s1 == "0")
                return false;
            if (s2 == "0")
                return true;
            int i = 0;
            int j = 0;
            for (; i < s1.size() && j < s2.size(); i++,j++)
            {
                if (s1[i] < s2[j])
                    return false;
                else if (s1[i] > s2[j])
                    return true;
            }
            if (i == j && i == s1.size() && j == s2.size() && s1[i - 1] == s2[j - 1])
                return true;
            if (stoll(s1 + s2) >= stoll(s2 + s1))
                return true;
            return false;
        });
        string ans = "";
        for (const auto i : n1)
        {
            ans += i;
        }
        if (ans[0] == '0')
            return "0";
        return ans;
    }
};