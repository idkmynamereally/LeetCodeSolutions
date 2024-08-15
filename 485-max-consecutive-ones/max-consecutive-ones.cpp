class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans = 0;
        int ret = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 1)
                ans++;
            else
                {ret = ret > ans ? ret : ans;ans = 0;}
        }
        ret = ret > ans ? ret : ans;
        return ret;
    }
};