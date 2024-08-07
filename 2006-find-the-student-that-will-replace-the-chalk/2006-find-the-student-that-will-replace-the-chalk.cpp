#define ll long long

class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k)
    {
        ll sum = 0;
        for (int i = 0; i < chalk.size(); i++)
            sum += chalk[i];
        
        k = k - ((k/sum) * sum);

        for (int i = 0; i < chalk.size(); i++)
        {
            if (chalk[i] > k)
                return i;
            k -= chalk[i];
        }
        return 0;
    }
};