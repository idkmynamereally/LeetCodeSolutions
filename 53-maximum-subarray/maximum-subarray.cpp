int speedUp = [] {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    return 0;
}();

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int ans = INT_MIN;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            ans = ans > sum ? ans : sum;
            sum = sum > 0 ? sum : 0;
        }
        return ans;
    }
};