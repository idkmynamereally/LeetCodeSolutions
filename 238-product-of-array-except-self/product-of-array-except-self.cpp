class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> pre(nums.size() + 1);
        vector<int> suf(nums.size() + 1);

        int m = 1;

        for (int i = 0; i < nums.size(); i++)
        {
            pre[i] = m;
            m *= nums[i];
        }


        m = 1;
        suf[nums.size()] = 1;

        for (int i = nums.size() - 1; i >= 0; i--)
        {
            suf[i] = m;
            m *= nums[i];
        }

        vector<int> ans;

        for (int i = 0; i < nums.size(); i++)
        {
            ans.push_back(pre[i] * suf[i]);
        }

        return ans;
    }
};