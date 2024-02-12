class Solution
{
public:
    int lengthOfLIS(vector<int>& nums) 
    {
        vector<int> dp(nums.size(), 1);
        for (int i = nums.size() - 1; i >= 0; i--)
        {
            int ans = 0;
            for (int remIndex = i + 1; remIndex < nums.size(); remIndex++)
            {
                if (nums[remIndex] > nums[i])
                {
                    ans = ans > dp[remIndex] ? ans : dp[remIndex];
                }
            }
            dp[i] = ans + 1;
        }
        int ans = 1;
        for (int i : dp)
            ans = ans > i ? ans : i;
        return ans;
    }
};