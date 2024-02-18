class Solution
{
public:
    bool canPartition(vector<int>& nums)
    {
        unordered_map<int, unordered_map<int, bool>> map;   //<currIndex, <target, result>>
        int sum{ 0 };
        for (int i : nums)
            sum += i;

        if (sum % 2 != 0)
            return false;
        return recurse(nums, 0, sum / 2, map);
    }

    bool recurse(vector<int>& nums, int currIndex, int target, unordered_map<int, unordered_map<int, bool>>& map)
    {
        if (map.contains(currIndex))
        {
            if (map[currIndex].contains(target))
                return map[currIndex][target];
        }

        if (target == 0)
        {
            map[currIndex][target] = true;
            return true;
        }

        if (currIndex == nums.size())
        {
            map[currIndex][target] = false;
            return false;
        }

        if (recurse(nums, currIndex + 1, target - nums[currIndex], map))
        {
            map[currIndex][target] = true;
            return true;
        }
        if (recurse(nums, currIndex + 1, target, map))
        {
            map[currIndex][target] = true;
            return true;
        }

        map[currIndex][target] = false;

        return map[currIndex][target];
    }
};