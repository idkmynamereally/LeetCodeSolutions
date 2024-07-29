class Solution
{
public:
    int numTeams(vector<int>& rating) 
    {
        int ans = 0;
        for (int i = 0; i < rating.size(); i++)
        {
            ans += solve(i, rating);
        }

        return ans;
    }

    int solve(int curr, vector<int>& rating)
    {
        int leftSmaller = 0;
        int leftLarger = 0;
        int rightSmaller = 0;
        int rightLarger = 0;

        for (int i = 0; i < curr; i++)
        {
            if (rating[i] < rating[curr])
                leftSmaller++;
            else if (rating[i] > rating[curr])
                leftLarger++;
        }

        for (int i = curr + 1; i < rating.size(); i++)
        {
            if (rating[i] < rating[curr])
                rightSmaller++;
            else if (rating[i] > rating[curr])
                rightLarger++;
        }

        return ((leftSmaller * rightLarger) + (leftLarger * rightSmaller));
    }
};