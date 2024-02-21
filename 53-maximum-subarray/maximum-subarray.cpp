class Solution
{
public:
    int maxSubArray(vector<int>& nums)
    {
        std::ios::sync_with_stdio(0);
        std::cin.tie(0);
        int ans = INT_MIN;
        int currSum = 0;
        for (int i : nums)
        {
            currSum += i;
            ans = ans > currSum ? ans : currSum;
            currSum = currSum < 0 ? 0 : currSum;
        }
        return ans;
    }
};