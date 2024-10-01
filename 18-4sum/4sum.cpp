#define ll long long
class Solution{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> ans;
        for (int i = 0; i < n - 3; i++)
        {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            for (int j = i + 1; j < n - 2; j++)
            {
                if (j > i + 1 && nums[j] == nums[j - 1])
                    continue;
                ll sum = nums[i] + nums[j];
                ll targ = target-sum;
                int l = j + 1;
                int r = n - 1;

                while (l < r)
                {
                    ll tot = nums[l] + nums[r];
                    if (tot == targ)
                    {
                        ans.push_back(vector<int>{nums[i], nums[j], nums[l], nums[r]});
                        l++;
                        r--;
                        while (l < nums.size() && nums[l] == nums[l - 1])
                            l++;
                        while (r > l && nums[r] == nums[r + 1])
                            r--;
                    }
                    else if (tot > targ)
                        r--;
                    else
                        l++;
                }
            }
        }
        return ans;
    }
};