class Solution {
public:
    int findComplement(int num)
    {
        return bitis(num);
    }
    int bitis(int num)
    {
        int a = 0;
        int po = 0;
        while (num)
        {
            if (num % 2 == 0)
                a += pow(2, po);
            po++;
            num /= 2;
        }
        return a;
    }
};