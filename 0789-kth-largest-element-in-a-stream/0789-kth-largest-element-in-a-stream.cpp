class KthLargest 
{
public:
    std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;
    int k;
    KthLargest(int k, vector<int>& nums)
    {
        this->k = k;
        for (int i : nums)
            minHeap.push(i);
        while (minHeap.size() > k)
            minHeap.pop();
    }

    int add(int val)
    {
        minHeap.push(val);
        while (minHeap.size() > k)
            minHeap.pop();
        return minHeap.top();
    }
};