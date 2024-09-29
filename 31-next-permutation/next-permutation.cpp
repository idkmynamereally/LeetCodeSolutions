class Solution
{
public:
    void nextPermutation(vector<int> &nums)
    {
        int i = nums.size() - 2;

        for (; i >= 0; i--)
        {
            if (nums[i + 1] > nums[i])  
                break;
        }

        if (i == -1)
        {
            reverse(nums.begin(), nums.end());
            return;
        }

        int nextBigger = -1;
        
        for (int j = i + 1; j < nums.size(); j++)
        {
            if (nums[j] > nums[i])
            {
                if (nextBigger == -1)
                    nextBigger = j;
                else
                    nextBigger = nums[nextBigger] < nums[j] ? nextBigger : j;
            }
        }

        swap(nums[i], nums[nextBigger]);

        reverse(nums.begin() + i + 1, nums.end());
    }
};