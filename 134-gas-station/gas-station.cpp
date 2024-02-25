class Solution
{
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost)
    {
        vector<int> affect(gas.size(), 0);
        int gasT = 0;
        int costT = 0;
        for (int i = 0; i < affect.size(); i++)
        {
            gasT += gas[i];
            costT += cost[i];
            affect[i] = gas[i] - cost[i];
        }

        if (gasT < costT)
            return -1;

        int l = 0;
        int r = 0;
        int ans = 0;
        int sum = 0;

        while (l < gas.size())
        {
            slidingWindow(l, r, affect, sum);
            if ((r == l) && sum >= 0)
                return l;
            if (r <= l)
                return -1;
            l = r;
        }

        return ans;
    }
    void slidingWindow(int& l, int& r, vector<int>& affect, int& sum)
    {
        sum = affect[l];
        int size = affect.size();
        r = (l + 1) % size;

        while (sum >= 0)
        {
            if (r == l)
            {
                return;
            }
            sum += affect[r];
            r = (r + 1) % size;
        }
    }
    void printWindow(int l, int r, vector<int>& affect)
    {
        int size = affect.size();
        cout << "Window : ";
        for (int i = l; i != r; i++, i = i % size)
        {
            cout << affect[i] << " (" << i << ")" << ", ";
        }
        cout << affect[r] << " (" << r << ")" << ", " << "\n";
    }
};