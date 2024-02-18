class Solution
{
public:
    bool canPartition(vector<int>& nums)
    {
        int sum{ 0 };
        for (int i : nums)
            sum += i;

        if (sum % 2 != 0)
            return false;

        vector<vector<int>> dp(nums.size(), vector<int>(sum/2 + 1, -1)); 
        return recurse(nums, 0, sum / 2, dp);
    }

    bool recurse(vector<int>& nums, int currIndex, int target, vector<vector<int>>& dp)
    {
        if (target < 0)
            return false;

        if (target == 0)
            return true;

        if (currIndex == nums.size())
            return false;

        if (dp[currIndex][target] != -1)
            return dp[currIndex][target];

        bool inc = recurse(nums, currIndex + 1, target - nums[currIndex], dp);
        bool exc = recurse(nums, currIndex + 1, target, dp);

        return dp[currIndex][target] = inc || exc;
    }
};