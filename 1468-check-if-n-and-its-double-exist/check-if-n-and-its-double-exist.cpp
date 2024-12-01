class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_set<int> set;
        for (int i : arr)
        {
            if (set.contains(i * 2) || (i % 2 == 0 && set.contains(i / 2)))
                return true;
            set.insert(i);
        }
        return false;
    }
};