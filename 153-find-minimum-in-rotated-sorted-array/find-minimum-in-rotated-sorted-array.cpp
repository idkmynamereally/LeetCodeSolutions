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
            int l = nums[left];
            int r = nums[right];
            int m = nums[middle];

            //std::cout << "l : " << l << " m : " << m << " r : " << r << "\n";

            if (l <= r && l <= m)
                return l;
            if (l <= m && m >= r)
                left = middle + 1;
            else if (l > m)
                right = middle;
        }
        return 0;
    }
};