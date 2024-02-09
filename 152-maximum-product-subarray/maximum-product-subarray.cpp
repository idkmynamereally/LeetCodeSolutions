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
            int curr = nums[i];
            int lastMin = minMul[i - 1];
            int lastMax = maxMul[i - 1];

            int c1 = lastMin * curr;
            int c2 = lastMax * curr;
            
            minMul[i] = (c1 < c2 ? c1 : c2);
            minMul[i] = curr < minMul[i] ? curr : minMul[i];

            maxMul[i] = (c1 > c2 ? c1 : c2);
            maxMul[i] = curr > maxMul[i] ? curr : maxMul[i];
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