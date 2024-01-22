template <typename T>
class TreeNodeBst
{
public:
	T data;
	TreeNodeBst* left;
	TreeNodeBst* right;

	TreeNodeBst<T>(T data)
	{
		this->data = data;
		this->left = nullptr;
		this->right = nullptr;
	}
};

template <typename T>
class BST
{
private:
	void inOrderWalk(TreeNodeBst<T>* root, std::vector<int>& v)
	{
		if (root == NULL)
			return;
		inOrderWalk(root->left, v);
		v.push_back(root->data);
		inOrderWalk(root->right, v);
	}
	void preOrderWalk(TreeNodeBst<T>* root)
	{
		if (root == NULL)
			return;
		std::cout << root->data << "\n";
		preOrderWalk(root->left);
		preOrderWalk(root->right);
	}
	void postOrderWalk(TreeNodeBst<T>* root)
	{
		if (root == NULL)
			return;
		postOrderWalk(root->left);
		postOrderWalk(root->right);
		std::cout << root->data << "\n";
	}
public:
	TreeNodeBst<T>* root;

	BST() : root{ nullptr } {}

	std::vector<int> inOrderTraverse()
	{
		std::vector<int> nums;
		inOrderWalk(root, nums);
		return nums;
	}

	void insertNode(T data)
	{
		TreeNodeBst<T>* newNode = new TreeNodeBst(data);

		if (root == nullptr)
		{
			root = newNode;
			return;
		}

		TreeNodeBst<T>* temp = root;
		TreeNodeBst<T>* parent = nullptr;

		while (temp)
		{
			parent = temp;
			if (data < temp->data)
				temp = temp->left;
			else
				temp = temp->right;
		}

		if (data < parent->data)
			parent->left = newNode;
		else
			parent->right = newNode;
	}

	void deleteNode(TreeNodeBst<T>* node, TreeNodeBst<T>* parent)
	{
		if (node->left == nullptr)		//Either n.right is null or a tree either way it can be the subtree of parent
		{
			if (node == root)
			{
				root = root->right;
				return;
			}
			if (parent->left == node)
				parent->left = node->right;
			else if (parent->right == node)
				parent->right = node->right;
			return;
		}
		if (node->right == nullptr)
		{
			if (node == root)
			{
				root = root->left;
				return;
			}
			if (parent->left == node)
				parent->left = node->left;
			else if (parent->right == node)
				parent->right = node->left;
			return;
		}
		else		//Our node has both left and right children
		{
			TreeNodeBst<T>* succParent = node;
			TreeNodeBst<T>* succ = node->right;
			while (succ->left)
			{
				succParent = succ;
				succ = succ->left;
			}
			if (succ != node->right)		//If successor is deep we need to handle its right subtree
			{
				succParent->left = succ->right;
				succ->right = node->right;
			}
			if (node == root)
				root = succ;
			else if (parent->left == node)
				parent->left = succ;
			else if (parent->right == node)
				parent->right = succ;
			succ->left = node->left;
			return;
		}
	}

	TreeNodeBst<T>* searchNode(T key)
	{
		TreeNodeBst<T>* temp = root;

		while (temp && temp->data != key)
		{
			if (key < temp->data)
				temp = temp->left;
			else
				temp = temp->right;
		}
		return temp;
	}

	TreeNodeBst<T>* getMinimumFromTree()
	{
		getMinimum(root);
	}

	TreeNodeBst<T>* getMaximumFromTree()
	{
		getMaximum(root);
	}

	TreeNodeBst<T>* getMinimum(TreeNodeBst<T>* temp)
	{
		if (temp == nullptr)
			return temp;
		while (temp->left)
		{
			temp = temp->left;
		}
		return temp;
	}

	TreeNodeBst<T>* getMaximum(TreeNodeBst<T>* temp)
	{
		if (temp == nullptr)
			return temp;
		while (temp->right)
		{
			temp = temp->right;
		}
		return temp;
	}
};

class KthLargest 
{
public:
	BST<int> bst;
    int k;
    KthLargest(int k, vector<int>& nums)
    {
        this->k = k;
		for (int i : nums)
			bst.insertNode(i);
    }

    int add(int val)
    {
		bst.insertNode(val);
		std::vector<int> numsInOrder;
		numsInOrder = bst.inOrderTraverse();
		return numsInOrder[numsInOrder.size() - (k)];
    }
};