#include <iostream>
#include <vector>

using namespace std;

int speedUp = []
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    return 0;
}();

class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k)
    {
        int l = 1;
        int r = 0;

        for (int i : bloomDay)
            r = r > i ? r : i;

        int ans = -1;
        int days;

        while (l <= r)
        {
            days = l + floor((r - l) / 2);
            int boqs = boquets(bloomDay, m, k, days);
            
            if (boqs >= m)
            {
                ans = days;
                r = days - 1;
            }
            else
            {
                l = days + 1;
            }
        }
        return ans;
    }

    int boquets(vector<int>& arr, int m, int k, int days)
    {
        int count = 0;
        int bouqets = 0;

        for (int i = 0; i < arr.size(); i++)
        {
            if (arr[i] <= days)
                count++;
            else
                count = 0;
            
            if (count == k)
            {
                bouqets++;
                count = 0;
            }
        }
        return bouqets;
    }
};