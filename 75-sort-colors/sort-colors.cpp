class Solution {
public:
    void sortColors(vector<int>& nums)
    {
        int zeros = 0;
        int ones = 0;
        int twos = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            switch(nums[i])
            {
                case 0: zeros++;
                    break;
                case 1: ones++;
                    break;
                case 2: twos++;
                default:break;
            }
        }

        for (int i = 0; i < nums.size(); i++)
        {
            if (zeros){
                nums[i] = 0;zeros--;}
            else if (ones){
                nums[i] = 1;ones--;}
            else if (twos){
                nums[i] = 2;twos--;}
        }
    }
};