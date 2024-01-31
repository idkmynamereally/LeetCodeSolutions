class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) 
    {
        vector<vector<int>> ans;
        vector<int> curr;
        helper(ans, curr, nums, 0);
        return ans;
    }

    void helper(vector<vector<int>>& ans, vector<int>& curr, vector<int>& nums, int currIndex)
    {
        if (currIndex == nums.size())
        {
            ans.push_back(curr);
            return;
        }

        helper(ans, curr, nums, currIndex + 1);
        curr.push_back(nums[currIndex]);
        helper(ans, curr, nums, currIndex + 1);
        curr.pop_back();
    }
};