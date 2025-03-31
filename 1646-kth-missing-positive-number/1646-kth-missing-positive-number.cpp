class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int l = 0;
        int r = arr[arr.size() - 1] + k; 
        
        int ans = arr[0];
        
        if (k < arr[0])
            return k;
        
        k = k - arr[l] + 1;
        int i = 0;

        while (k && i < arr.size())
        {
            if (arr[i] == ans)
            {
                ans++;
                i++;
                continue;
            }
            
            while (ans != arr[i] && k)
            {
                k--;
                if (!k)
                    return ans;
                ans++;
            } 
            ans++;
            i++;
        }

        return ans + k - 1;
    }
};