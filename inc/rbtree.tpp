#ifndef RBTREE_T
# define RBTREE_T

# ifndef RBTREE_H
#  error __FILE__ should only be included via rbtree.hpp
# endif

namespace ft
{

	template<class T, class Node>
	void	rbtree<T, Node>::insert(const value_type &val)
	{
		DEBUG_PRINT("rbtree : insert")
		try
		{
			Node *newNode = new Node;
			Node *newLeaf_1 = new Node;
			Node *newLeaf_2 = new Node;
			newNode->setData(val);
			newNode->left = newLeaf_1;
			newNode->left->parent = newNode;
			newNode->left->color = BLACK;
			newNode->right = newLeaf_2;
			newNode->right->parent = newNode;
			newNode->right->color = BLACK;
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
		if (root == NULL) // cas ou _root est null, ie l'arbre est vide
		{
			root = toInsert;
			root->color = BLACK;
			return ;
		}
		if (root->data == NULL) // on est sur une feuille
		{
			delete root;
			root = toInsert;
			root->parent = parent;
			/*
			   else if (parent->color == RED)
				insertFix(root);
			*/
			return ;
		}
		if (*(toInsert->data) < *(root->data))
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
			std::cout << "    ";
		std::cout << "[" << (root->color == RED ? "\x1b[31m" : "\x1b[30;47m");
		if (root->data == NULL)
			std::cout << "L";
		else
			std::cout << *(root->data);
		std::cout << "\x1b[0m]"<< std::endl;
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

	template<class T, class Node>
	void	rbtree<T, Node>::rightRotate(Node * &root)
	{
		Node	*y = root;
		Node	*x = root->left;
		Node	*parent = root->parent;
		if (x && x->right) // if x has a right subtree, assign y as parent of right subtree of x
		{
			x->right->parent = y;
			y->left = x->right;
		}
		if (y->parent == NULL) // if parent of y is null, make x as root of tree
			_root = x;
		else if (y == parent->right) //else if y is the right child of p, make x as right child of p
		{
			parent->right = x;
			x->parent = parent;
		}
		else // else assign x as the left child of p
		{
			parent->left = x;
			x->parent = parent;
		}
		y->parent = x; // Make x as the parent of y
		x->right = y;

	}

	template<class T, class Node>
	void	rbtree<T, Node>::destroyTree(Node * &root)
	{
		if (root == NULL)
			return;
		destroyTree(root->left);
		destroyTree(root->right);
		delete root;
	}
};

#endif
