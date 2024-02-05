class Solution
{
public:
    int rob(vector<int>& nums) 
    {
        for (int i = nums.size() - 1; i >= 0; i--)
        {
            int max = nums[i];
            for (int j = i + 2; j < nums.size(); j++)
            {
                if (nums[i] + nums[j] > max)
                    max = nums[i] + nums[j];
            }
            nums[i] = max;
        }
        int ans {0};
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] > ans)
                ans = nums[i];
        }
        return ans;
    }
};