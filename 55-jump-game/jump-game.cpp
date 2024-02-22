class Solution
{
public:
    bool canJump(vector<int>& nums)
    {
        unordered_set<int> set;
        for (int i = nums.size() - 1; i >= 0; i--)
        {
            makeSet(nums, set, i);
        }
        return (set.contains(0));
    }

    void makeSet(vector<int>& nums, unordered_set<int>& set, int currIndex)
    {
        int maxJump = nums[currIndex];

        for (int i = currIndex; i <= (currIndex + maxJump); i++)
        {
            if (i >= (nums.size() - 1) || set.contains(i))
            {
                set.insert(currIndex);
                return;
            }
        }
    }
};