class min_heap
{
private:
	std::vector<ListNode*> nums;
	constexpr int left(int index)
	{
		return (2 * index + 1);
	}
	constexpr int right(int index)
	{
		return (2 * index + 2);
	}
	int parent(int index)
	{
		return (ceil((double)index / 2) - 1);
	}
public:
	void insertToHeap(ListNode* value)		//Inserts at leaf then propogates it up O(lgN)
	{
		nums.push_back(value);
		int index = nums.size() - 1;
		while (parent(index) >= 0 && nums[index]->val < nums[parent(index)]->val)
		{
			ListNode* temp = nums[index];
			nums[index] = nums[parent(index)];
			nums[parent(index)] = temp;
			index = parent(index);
		}
	}
	void popFromHeap()
	{
		if (nums.size() == 0)
			return;
		int leaf = nums.size() - 1;
		nums[0] = nums[leaf];
		nums.pop_back();
		minHeapifyNode(0);
	}

	ListNode* peekMin()
	{
		if (nums.size() > 0)
			return nums[0];
		else
			return NULL;
	}

	void minHeapifyNode(int index)		//The function takes a node and takes it downstream per minHeap. IMP : it does not go up even if it is smaller than parent.
	{
		int smallest = index;
		if (left(index) < nums.size() && nums[left(index)]->val < nums[smallest]->val)
			smallest = left(index);
		if (right(index) < nums.size() && nums[right(index)]->val < nums[smallest]->val)
			smallest = right(index);

		if (smallest != index)
		{
			ListNode* temp = nums[index];
			nums[index] = nums[smallest];
			nums[smallest] = temp;
			minHeapifyNode(smallest);
		}
	}

	void minHeapifyFullHeap()
	{
		for (int i = (nums.size() / 2) - 1; i >= 0; i--)
		{
			minHeapifyNode(i);
		}
	}

	bool isEmpty()
	{
		if (nums.size())
			return false;
		return true;
	}
};

class Solution 
{
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) 
    {
		min_heap h;
		for (auto p : lists)
		{
			if (p)
				h.insertToHeap(p);
		}
		ListNode* newHead = new ListNode(-1);		//Dummy Node;
		ListNode* temp = newHead;
		while (!h.isEmpty())
		{
			temp->next = h.peekMin();
			temp = temp->next;
			h.popFromHeap();
			if (temp->next)
				h.insertToHeap(temp->next);
		}
		newHead = newHead->next;
		return newHead;
    }
};