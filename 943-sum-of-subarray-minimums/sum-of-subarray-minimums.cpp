#define MOD 1000000007
#define ll long long
class Solution
{
public:
    int sumSubarrayMins(vector<int> &arr)
    {
        stack<int> st;
        int n = arr.size();
        vector<int> leftSmaller(n, -1);
        vector<int> rightSmaller(n, n);
        int ans = 0;

        for (int i = 0; i < n; i++)
        {
            int a = arr[i];
            while (!st.empty() && a < arr[st.top()])
            {
                rightSmaller[st.top()] = i;
                st.pop();
            }
            if (!st.empty())
                leftSmaller[i] = st.top();
            st.push(i);
        }

        for (int i = 0; i < n; i++)
        {
            int leftSubs = i - leftSmaller[i];
            int rightSubs = rightSmaller[i] - i;
            ll t = ((leftSubs % MOD) * (rightSubs % MOD)) % MOD;
            t = (arr[i] * t) % MOD;
            ans = (ans + t) % MOD;
        }
        return ans;
    }
};