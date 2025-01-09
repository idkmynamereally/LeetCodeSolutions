class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> s;
        vector<int> ans;

        for (int i = 0; i < nums.size(); i++)
        {
            if (s.contains(target - nums[i]))
            {
                ans.push_back(i);
                ans.push_back(s[target - nums[i]]);
            }
            s[nums[i]] = i;
        }

        return ans;
    }
};