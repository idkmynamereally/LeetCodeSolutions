class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> s;
        for (int x = 0; x < nums.size(); x++)
        {
            int i = nums[x];
            if (s.contains(i))
                return true;
            s.insert(i);
        }
        return false;
    }
};