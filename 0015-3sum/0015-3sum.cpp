class Solution {
public:
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums)
    {
        std::vector<std::vector<int>> ans;
        std::sort(nums.begin(), nums.end());

        for (int a = 0; a < nums.size() && nums[a] <= 0; a++)
        {
            if (a > 0 && nums[a - 1] == nums[a])
                continue;
            int l = a + 1;
            int r = nums.size() - 1;

            while (l < r)
            {
                int sum = nums[l] + nums[r] + nums[a];
                if (sum < 0)
                    l++;
                else if(sum > 0)
                    r--;
                else
                {
                    ans.push_back(std::vector<int>{nums[a], nums[l], nums[r]});
                    l++;
                    while (l < r && nums[l] == nums[l-1])
                    {
                        l++;
                    }
                }
            }
        }
        return ans;
    }
};