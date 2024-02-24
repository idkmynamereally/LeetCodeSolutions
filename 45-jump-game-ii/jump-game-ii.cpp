class Solution
{
public:
    int jump(vector<int>& nums)
    {
        vector<int> dp(nums.size(), INT_MAX - 1);
        dp[nums.size() - 1] = 0;
        for (int i = nums.size() - 2; i >= 0; i--)
        {
            int ans = INT_MAX - 1;
            int maxJump = nums[i];
            for (int jump = maxJump; jump >= 0; jump--)
            {
                if ((i + jump) >= (nums.size() - 1))
                {
                    ans = 1;
                    break;
                }
                if (dp[i + jump] < ans)
                    ans = dp[i + jump] + 1;
            }
            dp[i] = ans;
            //cout << "i : " << i << " " << dp[i] << "\n";
        }
        return dp[0];
    }
};