auto init = [](){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();

class Solution {
public:
    //Approach : All values that have a left neighbor cannot be the start of
    // a sequence of consecutive numbers. so we go to every number if it has a
    // left neighbor we skip if not we see how long of a sequence it has
    int longestConsecutive(std::vector<int>& nums) 
    {
        int max = 0;
        std::unordered_set<int> allValues;
        for (int i : nums)
        {
            allValues.insert(i);
        }
        for (int i : nums)
        {
            if (allValues.contains(i - 1))
                continue;
            else
            {
                int count = 1;
                int n = i;
                while (allValues.contains(n + count))
                {
                    count++;
                }
                max = max > count ? max : count;
            }
        }
        return max;
    }
};