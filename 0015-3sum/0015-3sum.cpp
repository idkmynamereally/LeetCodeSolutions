int speedUp = []
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    return 0;
}();

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for (int a = 0; a < nums.size() - 2; a++)
        {
            if (a > 0 && nums[a] == nums[a - 1])
                continue;
            int target = -nums[a];
            int l = a + 1;
            int r = nums.size() - 1;

            while (l < r)
            {
                int tot = nums[l] + nums[r];
                if (tot == target)
                {
                    ans.push_back(vector<int>{nums[a], nums[l], nums[r]});
                    l++;
                    r--;
                    while (l < nums.size() && nums[l] == nums[l - 1])
                        l++;
                    while (r > l && nums[r] == nums[r + 1])
                        r--;
                }
                else if (tot > target)
                    r--;
                else
                    l++;
            }
        }
        return ans;
    }
};