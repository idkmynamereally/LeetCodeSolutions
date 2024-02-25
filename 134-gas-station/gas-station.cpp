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

        for (int i = 0; i < affect.size(); i++)
        {
            int sum = 0;
            for (int j = i; j < affect.size(); j++)
            {
                sum += affect[j];
                if (sum < 0)
                {
                    i = j;
                    break;
                }
            }
            if (sum >= 0)
                return i;
        }
        return -1;
    }
};