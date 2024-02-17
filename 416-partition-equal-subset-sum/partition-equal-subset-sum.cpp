class Solution
{
public:
    bool canPartition(vector<int>& nums)
    {
        unordered_map<int, unordered_map<int, bool>> map;   //<Target, <currIndex, result>>
        int sum{ 0 };
        for (int i : nums)
            sum += i;

        if (sum % 2 != 0)
            return false;
        return recurse(nums, 0, sum / 2, map);
    }

    bool recurse(vector<int>& nums, int currIndex, int target, unordered_map<int, unordered_map<int, bool>>& map)
    {
        if (currIndex == nums.size())
        {
            return false;
        }
        if (map.contains(target))
        {
            if (map[target].contains(currIndex))
                return map[target][currIndex];
        }

        if (nums[currIndex] == target)
        {
            map[target][currIndex] = true;
            return true;
        }
        
        if (recurse(nums, currIndex + 1, target - nums[currIndex], map))
            return true;

        if (recurse(nums, currIndex + 1, target, map))
            return true;

        map[target][currIndex] = false;
        return false;
    }
};