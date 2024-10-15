class Solution {
public:
    int findPeakElement(vector<int>& arr) {
        if (arr.size() == 1)
            return 0;
        for (int i = 1; i < arr.size() - 1; i++)
        {
            if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1])
                return i;
        }
        if (arr[0] > arr[1])
            return 0;
        if (arr[arr.size() - 1] > arr[arr.size() - 2])
            return arr.size() - 1;
        return 0;
    }
};