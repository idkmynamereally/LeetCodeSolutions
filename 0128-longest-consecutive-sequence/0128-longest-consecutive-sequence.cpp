class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        unordered_set<int> set;
        for (int i : nums)
            set.insert(i);

        int ans = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            int head = nums[i];
            while (set.count(head))
            {
                head--;
            }
            head++;
            int t = 0;
            while (set.count(head))
            {
                set.erase(head);
                head++;
                t++;
            }
            ans = ans > t ? ans : t;
        }
        return ans;
    }
};