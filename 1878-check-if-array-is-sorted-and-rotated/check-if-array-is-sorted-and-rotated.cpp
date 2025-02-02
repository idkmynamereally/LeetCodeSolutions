class Solution {
public:
    bool check(vector<int>& nums)
    {
        int i = 1;
        for (; i < nums.size(); i++)
        {
            if (nums[i] < nums[i - 1])
                break;
        }
        
        if (i == nums.size())
            return true;

        for (int j = (i + 1) % nums.size(); j != i; j = (j + 1) % nums.size())
        {
            if (j == 0)
            {
                if (nums[0] < nums[nums.size() - 1])
                    return false;
            }
            else if (nums[j] < nums[j - 1])
                return false;
        }

        return true;
    }
};