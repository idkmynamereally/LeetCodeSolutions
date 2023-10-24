class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& numbers, int target) 
    {
        std::vector<int> ans(2);
        int l = 0; 
        int r = numbers.size() - 1;

        while (l < r)
        {
            int sum = numbers[l] + numbers[r];
            if (sum == target)
            {
                ans[0] = l + 1;
                ans[1] = r + 1;
                return ans;
            }
            else if (sum < target)
            {
                l++;
            }
            else if (sum > target)
            {
                r--;
            }
        }
        return ans;
    }
};