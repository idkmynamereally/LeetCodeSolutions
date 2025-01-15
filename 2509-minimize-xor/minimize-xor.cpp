class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int num = 1;
        int k = 0;
        int temp = num2;
        while (temp)
        {
            if (temp & 1)
                k++;
            temp >>= 1;
        }

        int ans = 0;
        int k2 = 0; //set bits in num1
        temp = num1;

        while (temp)
        {
            if (temp & 1)
                k2++;
            temp >>= 1;
        }

        cout << k2 << k;

        if (k2 == k)
            return num1;
        if (k2 > k)
        {
            int n = 0;
            ans = num1;
            while (k2 != k)
            {
                if (ans & (1 << n)) //num1 has the current bit set
                {
                    ans = ans ^ (1 << n);
                    k2--;
                }
                n++;
            }
            return ans;
        }
        else
        {
            int n = 0;
            ans = num1;

            while (k2 != k)
            {
                if (!(ans & (1 << n)))
                {
                    ans = ans | (1 << n);
                    k2++;
                }
                n++;
            }
            return ans;
        }
        return ans;
    }
};