class Solution
{
public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> ans;
        vector<int> curr;
        recurse(0, curr, nums, ans);
        return ans;
    }

    void recurse(int i, vector<int> curr, vector<int>& nums, vector<vector<int>>& ans)
    {
        if (i == nums.size())
        {
            ans.push_back(curr);
            return;
        }

        recurse(i + 1, curr, nums, ans);    //Dont take i
        curr.push_back(nums[i]);
        recurse(i + 1, curr, nums, ans);
    }
};