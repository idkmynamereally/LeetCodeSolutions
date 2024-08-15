class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int fives = 0;
        int tens = 0;
        int chwenchy = 0;

        for (int i = 0; i < bills.size(); i++)
        {
            if (bills[i] == 5)
            {
                fives++;continue;
            }
            else if (bills[i] == 10)
            {
                tens++;
                if (fives)
                    {fives--;}
                else
                    return false;
            }
            else{
                chwenchy++;
                if (fives && tens)
                    {fives--;tens--;continue;}
                else if (fives >= 3)
                    fives -= 3;
                else
                    return false;
            }
        }   
        return true;
    }
};