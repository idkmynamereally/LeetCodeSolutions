class Solution
{
public:
    int maxSubArray(vector<int>& nums)
    {
        int ans = INT_MIN;
        int left = 0;
        int right = 0;
        int currSum = 0;

        while (right < nums.size())
        {
            currSum += nums[right];

            ans = ans > currSum ? ans : currSum;

            if (currSum < 0)
            {
                left = right + 1;
                right = left;
                currSum = 0;
                continue;
            }
            else
            {
                right++;
            }
        }
        return ans;
    }
};