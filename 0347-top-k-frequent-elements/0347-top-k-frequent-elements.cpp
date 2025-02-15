class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        struct custom
        {
            bool operator() (const pair<int, int> a, const pair<int, int> b){
                return a.second < b.second;
            }
        };

        vector<int> ans;
        priority_queue<pair<int, int>, vector<pair<int, int>>, custom> p;

        unordered_map<int, int> mp;
        for (int i : nums)
            mp[i]++;

        for (auto it : mp)
            p.push(it);

        while (k--)
        {
            ans.push_back(p.top().first);
            p.pop();
        }

        return ans;
    }
};