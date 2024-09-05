class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        vector<bool> can(nums.size(), false);
        int closest = nums.size() - 1;

        for (int i = nums.size() - 2; i >= 0; i--)
        {
            if (i + nums[i] >= closest)
                closest = i;
        }

        return (closest == 0);
    }
};