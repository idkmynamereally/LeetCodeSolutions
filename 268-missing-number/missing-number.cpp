class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int totalSum = (n * (n + 1)) / 2;
        int sum = 0;
        for (int i : nums)
            sum += i;

        if (sum == totalSum)
            return 0;
        else
            return totalSum - sum;
    }
};