class Solution
{
public:
    int rob(vector<int>& nums)
    {
        if (nums.size() <= 3)
        {
            int max = 0;
            for (int i : nums)
                max = max > i ? max : i;
            return max;
        }
        vector<int> nums1(nums.begin(), --nums.end());
        vector<int> nums2(++nums.begin(), nums.end());
        return max(robI(nums1), robI(nums2));
    }

    int robI(vector<int>& nums)
    {
        for (int i = nums.size() - 3; i >= 0; i--)
        {
            int max = nums[i];
            for (int j = i + 2; j < nums.size(); j++)
            {
                if (nums[i] + nums[j] > max)
                    max = nums[i] + nums[j];
            }
            nums[i] = max;
        }
        return max(nums[0], nums[1]);
    }
};