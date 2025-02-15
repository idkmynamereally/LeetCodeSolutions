class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> set;
        for (int i : nums)
        {
            if (set.contains(i))
                return true;
            set.insert(i);
        }
        return false;
    }
};