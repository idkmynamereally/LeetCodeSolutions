class Solution {
public:
    int search(vector<int>& nums, int target) 
    {
        ios::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);

        int start {0};
        int end = nums.size()-1;
        int middle{};

        while (start <= end)
        {
            middle = start + floor((end - start)/2);
            if (nums[middle] == target)
                return middle;
            else if (nums[middle] < target)
                start = middle + 1;
            else if (nums[middle] > target)
                end = middle - 1;
        }
        return -1;
    }
};