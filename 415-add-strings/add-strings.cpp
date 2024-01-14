class Solution {
public:
    string addStrings(string num1, string num2) 
    {
        std::string ans;
        if (num1.size() < num2.size())
        {
            std::swap(num1, num2);
        }

        int d1 = 0;
        int d2 = 0;
        int i1 = num1.size() - 1;
        int i2 = num2.size() - 1;

        bool carry = 0;

        int sum = 0;
        for (; i2 >= 0; i1--, i2--)
        {
            d1 = num1[i1] - '0';
            d2 = num2[i2] - '0';
            sum = d1 + d2 + carry;
            
            ans.append(to_string((sum) % 10));
            if (sum > 9)
                carry = 1;
            else
                carry = 0;
        }
        for (i1; i1 >= 0; i1--)
        {
            d1 = num1[i1] - '0';
            sum = d1 + carry;

            ans.append(to_string(sum % 10));
            if (sum > 9)
                carry = 1;
            else
                carry = 0;
        }
        if (carry)
            ans.append("1");

        reverse(ans.begin(), ans.end());  
        return ans;
    }
};