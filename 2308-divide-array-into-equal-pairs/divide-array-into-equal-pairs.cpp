class Solution {
public:
    bool divideArray(vector<int>& nums) {
        unordered_set<int> set;
        for (int i : nums)
        {
            if (set.contains(i))
                set.erase(i);
            else
                set.insert(i);
        }
        if (set.empty())
            return true;
        return false;
    }
};