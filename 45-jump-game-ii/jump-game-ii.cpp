class Solution
{
public:
    int jump(vector<int>& nums)
    {
        if (nums.size() == 1)
            return 0;
        int l = 0;
        int r = 0;
        int ans = 0;
        while (r < nums.size() - 1)
        {
            int farthest = r;
            for (int i = l; i <= r; i++)
            {
                farthest = farthest > (nums[i] + i) ? farthest : (nums[i] + i);
            }
            l = r + 1;
            r = farthest;
            ans++;
        }
        return ans;
    }
};