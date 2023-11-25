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
            
            if (target < nums[middle])
            {
                if (nums[left] <= nums[middle])
                {
                    if (target < nums[left])
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
                if (nums[middle] <= nums[right])
                {
                    if (target > nums[right])
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