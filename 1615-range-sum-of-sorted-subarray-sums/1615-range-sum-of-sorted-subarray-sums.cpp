class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right)
    {
        int mod = 1000000007;

        vector<int> prefixSum(nums.size());

        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            prefixSum[i] = sum;
            sum += nums[i] % mod;
        }

        vector<int> ans;

        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = i; j < nums.size(); j++)
            {
                int s = prefixSum[j] - prefixSum[i] + nums[j];
                ans.push_back(s);
            }
        }
        
        sort(ans.begin(), ans.end());

        int ret = 0;
        for (int i = left - 1; i < right; i++)
        {   
            ret += ans[i];
            ret %= mod;
        }
        return int(ret % mod);
    }
};