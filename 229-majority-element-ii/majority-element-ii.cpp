class Solution {
public:
    vector<int> majorityElement(vector<int>& nums)
    {
        unordered_map<int, int> mp;
        for (int i : nums)
        {
            mp[i]++;
        }
        vector<int> ans;
        int n = nums.size();
        for (const auto& p : mp)
        {
            if (p.second > n/3)
            {
                ans.push_back(p.first);
            }
        }
        return ans;
    }
};