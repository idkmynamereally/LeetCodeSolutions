class Solution {
public:
    int findMin(std::vector<int>& nums) 
    {
        int left{ 0 };
        int right = nums.size() - 1;
        int middle{ 0 };

        while (left <= right)
        {
            middle = left + floor((right - left) / 2);

            //std::cout << "l : " << l << " m : " << m << " r : " << r << "\n";

            if (nums[left] <= nums[right] && nums[left] <= nums[middle])
                return nums[left];
            if (nums[left] <= nums[middle] && nums[middle] >= nums[right])
                left = middle + 1;
            else if (nums[left] > nums[middle])
                right = middle;
        }
        return 0;
    }
};