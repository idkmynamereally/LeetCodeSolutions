class Solution
{
public:
    int findDuplicate(vector<int>& nums)
    {
        int i = 0;
        int slowI = 0;
        int fastI = 0;
        while (1)
        {
            slowI = nums[slowI];
            fastI = nums[nums[fastI]];
            if (slowI == fastI)
                break;
        }
        slowI = 0;
        while (1)
        {
            slowI = nums[slowI];
            fastI = nums[fastI];
            if (slowI == fastI)
                break;
        }
        return slowI;
    }
};