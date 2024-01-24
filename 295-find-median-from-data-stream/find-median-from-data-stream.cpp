class MedianFinder 
{
public:
    std::priority_queue<int> leftHeap;
    std::priority_queue<int, std::vector<int>, std::greater<int>> rightHeap;
    int median{ 0 };
    int count{ 0 };
    MedianFinder()
    {
        median = 0;
        count = 0;
    }

    void addNum(int num) 
    {
        if (count == 0)
        {
            median = num;
            count++;
            return;
        }
        if (num > median)
            rightHeap.push(num);
        else
            leftHeap.push(num);

        if ((rightHeap.size() - leftHeap.size()) == 2)
        {
            int temp = rightHeap.top();
            rightHeap.pop();
            leftHeap.push(median);
            median = temp;
        }
        else if (leftHeap.size() - rightHeap.size() == 2)
        {
            int temp = leftHeap.top();
            leftHeap.pop();
            rightHeap.push(median);
            median = temp;
        }
        count++;
    }

    double findMedian()
    {
        double ans{ 0 };
        ans = median;
        if (count % 2 == 0)
        {
            if (leftHeap.size() > rightHeap.size())
            {
                ans += leftHeap.top();
                return (ans / 2);
            }
            else
            {
                ans += rightHeap.top();
                return (ans / 2);
            }
        }
        return ans;
    }
};