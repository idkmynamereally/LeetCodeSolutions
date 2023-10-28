class Solution {
public:
    int maxArea(std::vector<int>& height) 
    {
        int length = 0;
        int breadth = 0;
        int maxVolume = -1;
        int currVolume = -1;

        int l = 0;
        int r = height.size() - 1;

        while (l < r)
        {
            length = r - l;
            breadth = height[l] < height[r] ? height[l] : height[r];
            currVolume = length * breadth;
            maxVolume = maxVolume > currVolume ? maxVolume : currVolume;

            if (height[l] > height[r])
            {
                int currHeight = height[r];
                while (r > l && height[r] <= currHeight)
                {
                    r--;
                }
            }
            else
            {
                int currHeight = height[l];
                while (l < r && height[l] <= currHeight)
                {
                    l++;
                }
            }
        }
        return maxVolume;
    }
};