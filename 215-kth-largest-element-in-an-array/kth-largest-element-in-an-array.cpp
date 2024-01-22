class Solution
{
public:
    int findKthLargest(vector<int>& nums, int k)
    {
        std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;
        for (int i : nums)
        {
            minHeap.push(i);
        }
        while (minHeap.size() > k)
        {
            minHeap.pop();
        }
        return minHeap.top();
    }
};