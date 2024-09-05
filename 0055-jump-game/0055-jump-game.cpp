class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        vector<bool> can(nums.size(), false);
        can[nums.size() - 1] = true;

        for (int i = nums.size() - 2; i >= 0; i--)
        {
            bool ans = false;
            for (int j = i + 1; !ans && j <= i + nums[i]; j++)
            {
                ans |= can[j];
            }
            can[i] = ans;
        }

        return can[0];
    }
};