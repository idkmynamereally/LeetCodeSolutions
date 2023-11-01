class MinStack
{
public:
    std::vector<std::pair<int,int>> stack;
    int topStack{};
    MinStack()
    {
        topStack = -1;
    }

    void push(int val)
    {
        topStack++;
        if (topStack >= stack.size())
            stack.resize(stack.size() + 2);
        stack[topStack].first = val;
        if (topStack == 0)
            stack[topStack].second = val;
        else
        {
            if (val < stack[topStack - 1].second)
                stack[topStack].second = val;
            else
                stack[topStack].second = stack[topStack - 1].second;
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
        return stack[topStack].first;
    }

    int getMin()
    {
        return stack[topStack].second;
    }
};