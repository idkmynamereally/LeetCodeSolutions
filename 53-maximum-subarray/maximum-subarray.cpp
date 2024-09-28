class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = nums[0];
        int ans = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            sum = sum > 0 ? sum : 0;
            sum += nums[i];
            ans = ans > sum ? ans : sum;
        }
        return ans;
    }
};