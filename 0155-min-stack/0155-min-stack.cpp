class MinStack 
{
public:
    std::vector<int> stack;
    std::vector<int> minArr;
    int topStack{};
    MinStack()
    {
        topStack = -1;
    }

    void push(int val) 
    {
        topStack++;
        stack.push_back(0);
        minArr.push_back(0);
        stack[topStack] = val;
        if (topStack == 0)
            minArr[topStack] = val;
        else
        {
            if (val < minArr[topStack - 1])
                minArr[topStack] = val;
            else
                minArr[topStack] = minArr[topStack - 1];
        }
    }

    void pop() 
    {
        if (topStack == -1)
            return;
        topStack--;
    }

    int top()
    {
        return stack[topStack];
    }

    int getMin()
    {
        return minArr[topStack];
    }
};