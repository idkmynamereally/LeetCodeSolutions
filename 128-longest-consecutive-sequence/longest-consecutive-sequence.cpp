class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> set;
        int ans = 0;
        for (int i : nums)
        {
            set.insert(i);
        }

        for (int i : nums)
        {
            int a = 0;
            while (set.contains(i))
                i--;
            i++;
            while (set.contains(i))
            {
                a++;
                set.erase(i);
                i++;
            }
            ans = max(ans, a);
        }
        return ans;
    }
};