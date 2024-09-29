class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        vector<int> preSum(nums.size() + 1);

        int sum = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            preSum[i] = sum;
            sum += nums[i];
        }

        preSum[nums.size()] = sum;
        int ans = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = i + 1; j <= nums.size(); j++)
            {
                int sub = preSum[j] - preSum[i];
                if (sub == k)
                    ans++;
            }
        }

        return ans;
    }
};