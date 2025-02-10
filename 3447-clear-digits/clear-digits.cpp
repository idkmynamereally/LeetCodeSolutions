class Solution {
public:
    string clearDigits(string s) {
        string ans = "";
        stack<int> lastChar;
        unordered_set<int> set;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] >= 'a' && s[i] <= 'z')
            {
                lastChar.push(i);
            }
            else
            {
                if (!lastChar.empty())
                {
                    set.insert(lastChar.top());
                    lastChar.pop();
                    set.insert(i);
                }
            }
        }

        for (int i = 0; i < s.size(); i++)
        {
            if (set.contains(i))
                continue;
            ans.push_back(s[i]);
        }

        return ans;
    }
};