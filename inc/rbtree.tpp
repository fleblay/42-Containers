#ifndef RBTREE_T
# define RBTREE_T

# ifndef RBTREE_H
#  error __FILE__ should only be included via rbtree.hpp
# endif

namespace ft
{

	template<class T, class Node>
	void	rbtree<T, Node>::insert(const T &val)
	{
		DEBUG_PRINT("rbtree : insert")
		Node	*newNode;

		try
		{
			newNode = new Node(val);
			insert(_root, NULL, newNode);
		}
		catch (std::exception &e)
		{
			DEBUG_PRINT("rbtree : insert exception catch")
			DEBUG_PRINT(e.what())
			throw;
		}
	}

	template<class T, class Node>
	Node * &rbtree<T, Node>::getRoot(void)
	{
		return _root;
	}

	template<class T, class Node>
	void	rbtree<T, Node>::print(void) const
	{
		print(_root, 0);
	}

	template<class T, class Node>
	void	rbtree<T, Node>::insert(Node * &root, Node *parent, Node *toInsert)
	{
		if (root == NULL)
		{
			root = toInsert;
			root->parent = parent;
			/*
			if (parent->color == RED)
				insertFix(root);
			*/
			return ;
		}
		if (toInsert->data < root->data)
			insert(root->left, root, toInsert);
		else
			insert(root->right, root, toInsert);
	}

	template<class T, class Node>
	void	rbtree<T, Node>::print(Node * const &root, unsigned int depth) const
	{
		if (root == NULL)
			return ;
		print(root->right, depth + 1);
		for (unsigned int i = 0; i < depth; i++)
			std::cout << "   ";
		std::cout << "[" << (root->color == RED ? "\x1b[31m" : "\x1b[30;47m") << root->data << "\x1b[0m]" << std::endl;
		print(root->left, depth + 1);
	}

	template<class T, class Node>
	void	rbtree<T, Node>::leftRotate(Node * &root)
	{
		Node	*x = root;
		Node	*y = root->right;
		Node	*parent = root->parent;
		if (y && y->left) // if y has a left subtree, assign x as parent of left subtree of y
		{
			y->left->parent = x;
			x->right = y->left;
		}
		if (x->parent == NULL) // if parent of x is null, make y as root of tree
			_root = y;
		else if (x == parent->left) //else if x is the left child of p, make y as left child of p
		{
			parent->left = y;
			y->parent = parent;
		}
		else // else assign y as the right child of p
		{
			parent->right = y;
			y->parent = parent;
		}
		x->parent = y; // Make y as the parent of x
		y->left = x;
	}
};

#endif
