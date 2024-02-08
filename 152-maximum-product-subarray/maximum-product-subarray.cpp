class Solution
{
public:
    int maxProduct(vector<int>& nums) 
    {
        int ans = INT_MIN;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 0)
            {
                ans = (0 > ans ? 0 : ans);
                continue;
            }
            int curr = 1;
            for (int j = i; j < nums.size(); j++)
            {
                curr *= nums[j];
                ans = (curr > ans ? curr : ans);
            }
        }
        return ans;
    }
};