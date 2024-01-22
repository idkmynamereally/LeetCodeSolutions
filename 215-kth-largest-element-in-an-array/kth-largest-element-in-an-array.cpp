#pragma GCC optimize ("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

//speedup i/o
#define speedIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

int init=[]{
    speedIO;
    return 0;
}();
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