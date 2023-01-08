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
		std::cout << "Start of insert" << std::endl;
		if (root == NULL) // cas ou _root est null, ie l'arbre est vide
		{
			std::cout << "Insert reached true tree root" << std::endl;
			root = toInsert;
			root->color = BLACK;
			return ;
		}
		if (root->data == NULL) // on est sur une feuille
		{
			std::cout << "Insert reached leaf" << std::endl;
			delete root;
			root = toInsert;
			root->parent = parent;
			if (root->parent->color == RED)
			{
				/*
				std::cout << "Need to fix color" << std::endl;
				std::cout << "Tree state before fix :" << std::endl;
				std::cout << "START PRINT" << std::endl;
				print();
				std::cout << "END PRINT" << std::endl;
				*/
				insertFix(root);
			}
			return ;
		}
		if (*(toInsert->data) < *(root->data))
		{
			std::cout << "insert left" << std::endl;
			insert(root->left, root, toInsert);
		}
		else
		{
			std::cout << "insert right" << std::endl;
			insert(root->right, root, toInsert);
		}
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
		//std::cout << "START PRINT before rotate" << std::endl;
		//print();
		//std::cout << "END PRINT" << std::endl;
		std::cout << "Left rotate start node whose value is : [" << *(x->data) << "]" << std::endl;
		if (y && y->left) // if y has a left subtree, assign x as parent of left subtree of y
		{
			std::cout << "Assigning left subtree of right rotating node to left rotating node" << std::endl;
			y->left->parent = x;
			x->right = y->left;
			std::cout << "OK" << std::endl;
		}
		if (x->parent == NULL) // if parent of x is null, make y as root of tree
		{
			std::cout << "Right rotating node is the new root" << std::endl;
			_root = y;
			std::cout << "OK" << std::endl;
		}
		else if (x == parent->left) //else if x is the left child of p, make y as left child of p
		{
			std::cout << "Updating the child of left rotating node's parent (new left child)" << std::endl;
			parent->left = y;
			y->parent = parent;
			std::cout << "OK" << std::endl;
		}
		else // else assign y as the right child of p
		{
			std::cout << "Updating the child of left rotating node's parent (new right child)" << std::endl;
			parent->right = y;
			y->parent = parent;
			std::cout << "OK" << std::endl;
		}
		x->parent = y; // Make y as the parent of x
		y->left = x;
		std::cout << "Left rotate end" << std::endl;
		//std::cout << "START PRINT after rotate" << std::endl;
		//print();
		//std::cout << "END PRINT" << std::endl;
	}

	template<class T, class Node>
	void	rbtree<T, Node>::rightRotate(Node * &root)
	{
		Node	*y = root;
		Node	*x = root->left;
		Node	*parent = root->parent;

		//std::cout << "START PRINT before rotate" << std::endl;
		//print();
		//std::cout << "END PRINT" << std::endl;
		std::cout << "Right rotate start node whose value is : [" << *(y->data) << "]" << std::endl;
		if (x && x->right) // if x has a right subtree, assign y as parent of right subtree of x
		{
			std::cout << "Assigning right subtree of left rotating node to right rotating node" << std::endl;
			x->right->parent = y;
			y->left = x->right;
			std::cout << "OK" << std::endl;
		}
		if (y->parent == NULL) // if parent of y is null, make x as root of tree
		{
			std::cout << "Left rotating node is the new root" << std::endl;
			_root = x;
			std::cout << "OK" << std::endl;
		}
		else if (y == parent->right) //else if y is the right child of p, make x as right child of p
		{
			std::cout << "Updating the child of right rotating node's parent (new right child)" << std::endl;
			parent->right = x;
			x->parent = parent;
			std::cout << "OK" << std::endl;
		}
		else // else assign x as the left child of p
		{
			std::cout << "Updating the child of right rotating node's parent (new left child)" << std::endl;
			parent->left = x;
			x->parent = parent;
			std::cout << "OK" << std::endl;
		}
		y->parent = x; // Make x as the parent of y
		x->right = y;
		std::cout << "Right rotate end" << std::endl;
		//std::cout << "START PRINT after rotate" << std::endl;
		//print();
		//std::cout << "END PRINT" << std::endl;
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
	template<class T, class Node>
	void	rbtree<T, Node>::insertFix(Node * &root)
	{
		Node *toCheck = root;
		Node *p = toCheck->parent;
		Node *gp = toCheck->parent->parent;

		std::cout << "Start of Fix" << std::endl;
		while (p->color == RED)
		{
			if (gp->left == p) // Le parent est le node gauche du gp, ie (oncle est node droit)
			{
				if (gp->right->color == RED)
				{
					std::cout << "Case 1.1" << std::endl;
					//gp->left->color = BLACK;
					p->color = BLACK;
					if (p == _root)
						break;
					gp->right->color = BLACK;
					gp->color = RED;
					toCheck = gp;
					p = toCheck->parent;
					gp = toCheck->parent->parent;
					std::cout << "End of case 1.1" << std::endl;
				}
				//Case 2
				else
				{
					std::cout << "Case 1.2" << std::endl;
					if (toCheck == p->right)
					{
						std::cout << "Case 1.2bis" << std::endl;
						toCheck = p;
						p = toCheck->parent;
						gp = toCheck->parent->parent;
						leftRotate(toCheck); // ajout d'un tmp
						std::cout << "End of case 1.2bis" << std::endl;
					}
					p->color = BLACK;
					if (p == _root)
						break;
					gp->color = RED;
					rightRotate(gp);
					std::cout << "End of case 1.2" << std::endl;
				}
			}
			else // Le parent est le node droit du gp, ie (oncle est node gauche)
			{
				//red == 1
				if (gp->left->color == RED)
				{
					std::cout << "Case 2.1" << std::endl;
					gp->left->color = BLACK;
					//gp->right->color = BLACK; // p->color ? == k->parent->color ?
					p->color = BLACK;
					if (p == _root)
						break;
					gp->color = RED;
					toCheck = gp;
					p = toCheck->parent;
					gp = toCheck->parent->parent;
					std::cout << "End of case 2.1" << std::endl;
				}
				else
				{
					std::cout << "Case 2.2" << std::endl;
					if (toCheck == p->left) // a break en un else + if ...
					{
						std::cout << "Case 2.2bis" << std::endl;
						toCheck = p;
						p = toCheck->parent;
						gp = toCheck->parent->parent;
						rightRotate(toCheck); // ajout d'un tmp
						std::cout << "End of case 2.2bis" << std::endl;
					}
					p->color = BLACK;
					if (p == _root)
						break;
					gp->color = RED;
					leftRotate(gp); // ajout d'un tmp
					std::cout << "End of case 2.2" << std::endl;
				}
			}
			std::cout << "Checking end conditon" << std::endl;
			if (toCheck == _root)
			{
				std::cout << "Break" << std::endl;
				break;
			}
		}
		std::cout << "Changing root color" << std::endl;
		_root->color = BLACK;
		std::cout << "End of Fix" << std::endl;
	}
};

#endif
