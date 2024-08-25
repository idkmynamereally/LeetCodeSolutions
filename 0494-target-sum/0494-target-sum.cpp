class Solution
{
public:
    int findTargetSumWays(vector<int> &nums, int target)
    {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
            sum += nums[i];
        int s1 = (target + sum) / 2;
        
        if (sum % 2 && !(target % 2))
            return 0;
        if (!(sum % 2) && target % 2)
            return 0;
        return recurse(nums, 0, s1);
    }

    int recurse(vector<int> &nums, int i, int t)
    {
        if (i == nums.size() && t == 0)
            return 1;
        if (i == nums.size() || t < 0)
            return 0;

        int take = recurse(nums, i + 1, t - nums[i]);
        int leave = recurse(nums, i + 1, t);

        return take + leave;
    }
};