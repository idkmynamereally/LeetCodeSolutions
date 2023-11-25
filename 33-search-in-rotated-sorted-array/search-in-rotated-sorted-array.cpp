class Solution {
public:
    int search(std::vector<int>& nums, int target) 
    {
        int left{ 0 };
        int right = nums.size() - 1;
        int middle{};

        while (left <= right)
        {
            middle = left + floor((right - left)/2);
            
            if (nums[middle] == target)
                return middle;
            
            int l = nums[left];
            int r = nums[right];
            int m = nums[middle];

            if (target < m)
            {
                if (l <= m)
                {
                    if (target < l)
                        left = middle + 1;
                    else
                        right = middle - 1;
                }
                else
                {
                    right = middle - 1;
                }
            }
            else
            {
                if (m <= r)
                {
                    if (target > r)
                        right = middle - 1;
                    else
                        left = middle + 1;
                }
                else
                {
                    left = middle + 1;
                }
            }
        }
        return -1;
    }
};