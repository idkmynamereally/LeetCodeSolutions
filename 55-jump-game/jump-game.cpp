class Solution
{
public:
    bool canJump(vector<int>& nums)
    {
        int closest = nums.size() - 1;
        makeSet(nums, closest, closest);
        return (closest == 0);
    }

    void makeSet(vector<int>& nums, int& closest, int currIndex)
    {
        if (currIndex < 0)
            return;
        int maxJump = nums[currIndex];
        if (currIndex + maxJump >= closest)
            closest = currIndex;
        makeSet(nums, closest, currIndex - 1);
    }
};