class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::map<int, int> m;       //<Value, Index>
        std::vector<int> ret;
        for (int i = 0; i < nums.size(); i++)
        {
            if (m.contains(target - nums[i]))
            {
                ret.push_back(i);
                ret.push_back(m[ target - nums[i] ]);
                break;
            }
            m[nums[i]] = i;
        }
        return ret;
    }
};