class Solution {
public:
    std::vector<int> productExceptSelf(std::vector<int>& nums) 
    {
        std::vector<int> prefix(nums.size());
        std::vector<int> suffix(nums.size());
        std::vector<int> ans(nums.size());
        prefix[0] = 1;
        suffix[nums.size() - 1] = 1;

        for (int i = 1; i < nums.size(); i++)
        {
            prefix[i] = prefix[i - 1] * nums[i - 1];
        }

        for (int i = nums.size()-2; i >= 0; i--)
        {
            suffix[i] = suffix[i + 1] * nums[i + 1];
        }

        for (int i = 0; i < nums.size(); i++)
        {
            ans[i] = prefix[i] * suffix[i];
        }
        return ans;
    }
};