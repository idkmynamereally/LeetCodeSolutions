class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int left = 0;
        int right = 0;

        int sum = 0;
        int max = INT_MIN;

        while (right < nums.size())
        {
            sum += nums[right];
            max = max > sum ? max : sum;
            while (left < nums.size() && sum < 0)
            {
                sum -= nums[left];
                left++;
            }
            if (left > right)
            {
                right = left;
                continue;
            }
            right++;
        }

        return max;
    }
};