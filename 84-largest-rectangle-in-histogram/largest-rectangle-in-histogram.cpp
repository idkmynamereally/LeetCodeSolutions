class Solution {
public:
    int largestRectangleArea(std::vector<int>& heights)
    {
        int highestArea = 0;

        int currIndex{};
        int leftIndex{};
        int rightIndex{};
        int length{};
        int currHeight{};
        int currArea{};

        for (currIndex = 0; currIndex < heights.size(); currIndex++)
        {
            currHeight = heights[currIndex];
            if (currHeight > highestArea)
                highestArea = currHeight;
            
            if (currIndex != 0 && currHeight == heights[currIndex - 1])
                continue;

            leftIndex = currIndex - 1;
            while (leftIndex >= 0 && heights[leftIndex] >= currHeight)
            {
                leftIndex--;
            }

            rightIndex = currIndex + 1;
            while (rightIndex < heights.size() && heights[rightIndex] >= currHeight)
            {
                rightIndex++;
            }

            currArea = currHeight * (rightIndex - leftIndex - 1);
            highestArea = highestArea > currArea ? highestArea : currArea;
        }
        return highestArea;
    }
};