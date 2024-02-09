class Solution
{
public:
    int maxProduct(vector<int>& nums) 
    {
        vector<int> maxMul(nums.size(), INT_MIN);
        vector<int> minMul(nums.size(), INT_MAX);

        maxMul[0] = nums[0];
        minMul[0] = nums[0];

        for (int i = 1; i < nums.size(); i++)
        {
            int c1 = minMul[i - 1] * nums[i];
            int c2 = maxMul[i - 1] * nums[i];
            
            minMul[i] = (c1 < c2 ? c1 : c2);
            minMul[i] = nums[i] < minMul[i] ? nums[i] : minMul[i];

            maxMul[i] = (c1 > c2 ? c1 : c2);
            maxMul[i] = nums[i] > maxMul[i] ? nums[i] : maxMul[i];
        }

        int ans = INT_MIN;
        for (int i : maxMul)
        {
            if (i > ans)
                ans = i;
        }
        return ans;
    }
};