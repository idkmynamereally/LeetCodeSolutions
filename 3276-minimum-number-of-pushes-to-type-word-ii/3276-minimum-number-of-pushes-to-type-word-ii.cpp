class Solution {
public:
    int minimumPushes(string word)
    {
        vector<int> mp(26);
        for (int i = 0; i < word.size(); i++)
        {
            mp[word[i] - 'a']++;
        }

        priority_queue<int, vector<int>> maxHeap;
        
        for (int i = 0; i < 26; i++)
        {
            maxHeap.push(mp[i]);
        }

        int ans = 0;
        int count = 0;

        while (!maxHeap.empty()) {
            count++;
            int t = maxHeap.top();
            maxHeap.pop();
            int mul = ceil((float)count / 8);
            ans += t * mul;
        }

        return ans;
    }
};