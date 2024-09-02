class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k)
    {
        int l = 0;
        int r = k - 1;

        deque<int> deq;
        vector<int> ans;

        for (int i = l; i <= r; i++)
        {
            int n = nums[i];
            while (!deq.empty() && n > deq.back())
                deq.pop_back();
            deq.push_back(n);
        }
        ans.push_back(deq.front());
        while (r < nums.size() - 1)
        {
            if (deq.front() == nums[l])
                deq.pop_front();
            l++;
            r++;
            while (!deq.empty() && deq.back() < nums[r])
                deq.pop_back();
            deq.push_back(nums[r]);
         
            ans.push_back(deq.front());
        }
        return ans;
    }
};