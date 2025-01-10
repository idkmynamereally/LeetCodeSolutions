class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        unordered_map<char, int> mp;
        
        for (int i = 0; i < words2.size(); i++)
        {
            unordered_map<char, int> mp2;
            for (char c : words2[i])
            {
                mp2[c]++;
            }

            for (char c = 'a'; c < 'z'; c++)
            {
                mp[c] = mp[c] > mp2[c] ? mp[c] : mp2[c];
            }
        }

        vector<string> ans;

        for (int i = 0; i < words1.size(); i++)
        {
            unordered_map<char, int> curr;
            for (char c : words1[i])
                curr[c]++;

            bool flag = 1;
            for (char c = 'a'; c < 'z'; c++)
            {
                if (curr[c] < mp[c])
                    flag = 0;
            }
            if (flag)
                ans.push_back(words1[i]);
        }

        return ans;
    }
};