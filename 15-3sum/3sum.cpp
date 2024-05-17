class Solution
{
public:
	vector<vector<int>> threeSum(vector<int>& nums)
	{
		vector<vector<int>> ans;
		std::sort(nums.begin(), nums.end());
		for (int i = 0; i < nums.size(); i++)
		{
            if (i != 0 && nums[i] == nums[i - 1])
                continue;
			int left = i + 1;
			int right = nums.size() - 1;
			int target = -1 * nums[i];
			while (left < right)
			{
                int sum = nums[left] + nums[right];
				if (sum == target)
				{
					ans.push_back(vector<int>{nums[i], nums[left], nums[right]});
                    do {left++;}
					while (left < right && nums[left] == nums[left - 1]);
                    do {right--;}
					while (right > left && nums[right] == nums[right + 1]);
				}
				else if (sum > target)
					right--;
				else
					left++;
			}
		}
		return ans;
	}
};