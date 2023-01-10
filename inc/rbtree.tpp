#ifndef RBTREE_T
# define RBTREE_T

# ifndef RBTREE_H
#  error __FILE__ should only be included via rbtree.hpp
# endif

#include <unistd.h>

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
			if (root->parent->color == RED)
			{
				insertFix(root);
			}
			return ;
		}
		if (*(toInsert->data) < *(root->data))
			insert(root->left, root, toInsert);
		else
			insert(root->right, root, toInsert);
	}

	/*
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
				std::cout << "Need to fix color" << std::endl;
				std::cout << "Tree state before fix :" << std::endl;
				std::cout << "START PRINT" << std::endl;
				print();
				std::cout << "END PRINT" << std::endl;
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
	*/

	template<class T, class Node>
	void	rbtree<T, Node>::print(Node * const &root, unsigned int depth) const
	{
		//std::cout << "depth is : [" << depth << "]" << std::endl;
		//usleep(100000);
		if (root == NULL)
			return ;
		print(root->right, depth + 1);
		for (unsigned int i = 0; i < depth; i++)
			std::cout << "    ";
		std::cout << "[" << (root->color == RED ? "\x1b[31m" : "\x1b[30;47m");
		if (root->data == NULL)
		{
			std::cout << "L";
		}
		else
		{
			if (root->left == NULL)
			{
				std::cout <<  "KO left child!!!";
				exit(1);
			}
			if (root->right == NULL)
			{
				std::cout <<  "KO Right child!!!";
				exit(1);
			}
			std::cout << *(root->data);
		}
		if (root->parent == NULL && root != _root)
		{
			std::cout <<  "KO parent!!!";
			exit(1);
		}
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
		if (x->parent == NULL || x == _root) // if parent of x is null, make y as root of tree
		{
			_root = y;
			_root->parent = NULL;
		}
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

	/*
	template<class T, class Node>
	void	rbtree<T, Node>::leftRotate(Node * &root)
	{
		Node	*x = root;
		Node	*y = root->right;
		Node	*parent = root->parent;

		if (x == _root)
			std::cerr << "Left Rotating with root as x" << std::endl;
		if (y == _root)
			std::cerr << "Left Rotating with root as y" << std::endl;
		if (parent == _root)
			std::cerr << "Left Rotating with root as parent" << std::endl;
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
		if (x->parent == NULL || x == _root) // if parent of x is null, make y as root of tree
		{
			std::cout << "Right rotating node is the new root" << std::endl;
			_root = y;
			_root->parent = NULL;
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
	*/

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
		if (y->parent == NULL || y == _root) // if parent of y is null, make x as root of tree
		{
			_root = x;
			_root->parent = NULL;
		}
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

	/*
	template<class T, class Node>
	void	rbtree<T, Node>::rightRotate(Node * &root)
	{
		Node	*y = root;
		Node	*x = root->left;
		Node	*parent = root->parent;

		if (x == _root)
			std::cerr << "Right Rotating with root as x" << std::endl;
		if (y == _root)
			std::cerr << "Right Rotating with root as y" << std::endl;
		if (parent == _root)
			std::cerr << "Right Rotating with root as parent" << std::endl;
		//if (y == _root && _root->parent->data != NULL)
			//std::cout << "WARNING : y is root and parent data is : " << *(_root->parent->data) << std::endl;
		//std::cout << "START PRINT before rotate" << std::endl;
		//print();
		//std::cout << "END PRINT" << std::endl;
		std::cout << "Right rotate start node whose value is : [" << *(y->data) << "]" << std::endl; // 675
		if (x && x->right) // if x has a right subtree, assign y as parent of right subtree of x
		{
			std::cout << "Assigning right subtree of left rotating node to right rotating node" << std::endl;
			x->right->parent = y;
			y->left = x->right;
			std::cout << "OK" << std::endl;
		}
		if (y->parent == NULL || y == _root) // if parent of y is null, make x as root of tree
		{
			std::cout << "Left rotating node is the new root" << std::endl;
			_root = x;
			_root->parent = NULL;
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
	*/

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
	Node	*rbtree<T, Node>::findNode(const value_type &toFind)
	{
		if (_root == NULL)
			return (NULL);
		return (findNode(_root, toFind));

	}

	template<class T, class Node>
	Node	*rbtree<T, Node>::findNode(Node * &root, const value_type &toFind)
	{
		if (root->data == NULL)
			return (NULL);
		if (*(root->data) == toFind)
			return (root);
		else if (*(root->data) > toFind)
			return (findNode(root->left, toFind));
		else
			return (findNode(root->right, toFind));
	}

	template<class T, class Node>
	int		rbtree<T, Node>::nbOfBlack(const Node * root) const
	{
		if (root->data == NULL)
			return (1);
		if (root->color == BLACK)
			return (1 + nbOfBlack(root->left));
		else
			return (nbOfBlack(root->left));
	}

	template<class T, class Node>
	bool rbtree<T, Node>::isOk(const Node * root) const
	{
		if (root->data == NULL)
			return (true);
		bool leftStatus = nbOfBlack(root->left);
		bool rightStatus = nbOfBlack(root->right);
		if (leftStatus != rightStatus)
			return (false);
		if (root != _root && root->color == RED && root->parent->color == RED)
			return (false);
		return(isOk(root->left) && isOk(root->right));
	}

	template<class T, class Node>
	bool rbtree<T, Node>::isOk(void) const
	{
		if (_root == NULL)
			return (true);
		return (isOk(_root));
	}

	template<class T, class Node>
	Node *rbtree<T, Node>::findMax(Node * root)
	{
		if (root->right->data == NULL)
			return (root);
		return (findMax(root->right));
	}

	template<class T, class Node>
	Node *rbtree<T, Node>::findMax(void)
	{
		if (_root == NULL)
			return (NULL);
		return (findMax(_root));
	}

	template<class T, class Node>
	Node *rbtree<T, Node>::findMin(Node * root)
	{
		if (root->left->data == NULL)
			return (root);
		return (findMin(root->left));
	}

	template<class T, class Node>
	Node *rbtree<T, Node>::findMin(void)
	{
		if (_root == NULL)
			return (NULL);
		return (findMin(_root));
	}

	template<class T, class Node>
	void	rbtree<T, Node>::transplant(Node * parent, Node *child)
	{
		Node *gp = parent->parent;

		std::cout << "Start Tranplant" << std::endl;
		std::cout << "Parent : [" << (parent->data ? *(parent->data) : -1 ) << "] - ";
		std::cout << "Child : [" << (child->data ? *(child->data) : -1 ) << "] - ";
		std::cout << "gParent : [" << (gp ? ( gp->data ? *(gp->data) : -1 ): -2) << "]" << std::endl;

		//changing child parent
		child->parent = parent->parent;
		//changing parent->parent child
		if (parent == _root)
		{
			std::cout << "Parent is root" << std::endl;
			_root = child;
		}
		else if (parent->parent->left == parent)
		{
			std::cout << "parent is left son of his own parent" << std::endl;
			parent->parent->left = child;
		}
		else
		{
			std::cout << "parent is right son of his own parent" << std::endl;
			parent->parent->right = child;
		}
		std::cout << "End Tranplant" << std::endl;
	}

	template<class T, class Node>
	void rbtree<T, Node>::deleteNode(Node * &root, const value_type &toDelete)
	{
		(void)root;
		Node *target = findNode(toDelete);
		color originalColor = target->color;
		Node *x;
		Node *y;

		std::cout << "Target is : [" << *(target->data) << "]" << std::endl;
		if (target->left->data == NULL)
		{
			std::cout << "Left child is leaf" << std::endl;
			x = target->right;
			transplant(target, x);
			delete target->left;
		}
		else if (target->right->data == NULL)
		{
			std::cout << "Right child is leaf" << std::endl;
			x = target->left;
			transplant(target, x);
			delete target->right;
		}
		else
		{
			std::cout << "No child is leaf" << std::endl;
			y = findMin(target->right); // plus petit superieur a target
			originalColor = y->color;
			x = y->right; // node droit du plus petit sup a target
			if (y->parent == target)
			{
				x->parent = y;
			}
			else
			{
				transplant(y, y->right);
				y->right = target->right;
				y->right->parent = y;
			}
			std::cout << "Second transplant" << std::endl;
			transplant(target, y);
			//Not so sure
			delete y->left;
			y->left = target->left;
			y->left->parent = y;
			y->color = originalColor;
		}
		if (originalColor == BLACK)
		{
			//deleteFix(x);
		}
		delete target;
	}

	template<class T, class Node>
	void rbtree<T, Node>::deleteNode(const value_type &toDelete)
	{
		if (_root == NULL)
		{
			std::cout << "Tree is empty" << std::endl;
			return ;
		}
		if (findNode(toDelete) == NULL)
		{
			std::cout << "Value does not exist" << std::endl;
			return ;
		}
		return (deleteNode(_root, toDelete));
	}

	template<class T, class Node>
	void	rbtree<T, Node>::insertFix(Node * &root)
	{
		Node *toCheck = root;
		Node *p = toCheck->parent;
		Node *gp = toCheck->parent->parent;
		Node *u = (gp->left == p ? gp->right : gp->left);

		while (toCheck != _root && toCheck->color == RED && p->color == RED)
		{
			if (u->color == RED)
			{
				p->color = BLACK;
				u->color = BLACK;
				if (gp != _root)
					gp->color = RED;
				toCheck = gp;
				if (toCheck != _root)
				{
					p = toCheck->parent;
					if (p != _root)
					{
						gp = toCheck->parent->parent;
						u = (gp->left == p ? gp->right : gp->left);
					}
				}
			}
			else // Uncle color is black
			{
				if (toCheck == p->left && p == gp->left)
				{
					rightRotate(gp);
					swapColor(p, gp);
				}
				else if (toCheck == p->right && p == gp->right)
				{
					leftRotate(gp);
					swapColor(p, gp);
				}
				else if (toCheck == p->right && p == gp->left)
				{
					leftRotate(p);
					//Next is LL
					rightRotate(gp);
					swapColor(toCheck, gp);
				}
				else if (toCheck == p->left && p == gp->right)
				{
					rightRotate(p);
					//Next is RR
					leftRotate(gp);
					swapColor(toCheck, gp);
				}
				toCheck = gp;
			}
			if (toCheck != _root)
			{
				p = toCheck->parent;
				if (p != _root)
				{
					gp = toCheck->parent->parent;
					u = (gp->left == p ? gp->right : gp->left);
				}
			}
		}
	}

	/*
	template<class T, class Node>
	void	rbtree<T, Node>::insertFix(Node * &root)
	{
		Node *toCheck = root;
		Node *p = toCheck->parent;
		Node *gp = toCheck->parent->parent;
		Node *u = (gp->left == p ? gp->right : gp->left);

		int go_out = 0;

		std::cout << "Start of Fix" << std::endl;
		//while (toCheck != _root && p->color == RED)
		while (toCheck != _root && toCheck->color == RED && p->color == RED)
		{
			std::cout << "toCheck is now : [" << *(toCheck->data) << "]" << std::endl
							<< "parent : [" << (p->data != NULL ? *(p->data) : -1) << "]"
							<< "uncle [" << (u->data != NULL ? *(u->data) : -1) << "]"
							<< "gp : [" << (gp->data != NULL ? *(gp->data) : -1) << std::endl;
				if (*(toCheck->data) == 485 && *root->data == 550)
				{
					//print();
					//exit(0);
					//go_out = 1;
				}
			if (u->color == RED)
			{
				std::cout	<< "Case " << (u == gp->left ? "Left" : "Right")
							<< " Uncle is Red : changing parent : [" << (p->data != NULL ? *(p->data) : -1) << "]"
							<< "and uncle [" << (u->data != NULL ? *(u->data) : -1)
							<< "] color to black, and grandfather : [" << (gp->data != NULL ? *(gp->data) : -1)
							<< "] to red" << std::endl;
				p->color = BLACK;
				u->color = BLACK;
				if (gp != _root)
					gp->color = RED;
				toCheck = gp;
				std::cout << "toCheck is now : [" << *(toCheck->data) << "]" << std::endl;
				if (toCheck != _root)
				{
					std::cout << "toCheck is not root, setting parent" << std::endl;
					p = toCheck->parent;
					if (p != _root)
					{
						std::cout << "toCheck parent is not root, setting gp and uncle" << std::endl;
						gp = toCheck->parent->parent;
						u = (gp->left == p ? gp->right : gp->left);
					}
				}
				std::cout << "End of case Right Uncle is Red" << std::endl;
			}
			else // Uncle color is black
			{
				std::cout<< "Uncle is Black" << std::endl;
				if (toCheck == p->left && p == gp->left)
				{
					std::cout<< "Left Left Case path from gp" << std::endl;
					rightRotate(gp);

					color tmp = p->color;
					p->color = gp->color;
					//if (gp != _root)
						gp->color = tmp;
					//toCheck = gp;
					toCheck = gp;
					std::cout << "toCheck is now : [" << *(toCheck->data) << "]" << std::endl;
				}
				else if (toCheck == p->right && p == gp->right)
				{
					std::cout<< "Right Right Case path from gp" << std::endl;
					leftRotate(gp);

					color tmp = p->color;
					p->color = gp->color;
					//if (gp != _root)
						gp->color = tmp;
					toCheck = gp;
					std::cout << "toCheck is now : [" << *(toCheck->data) << "]" << std::endl;
				}
				else if (toCheck == p->right && p == gp->left)
				{
					std::cout<< "Left Right Case path from gp" << std::endl;
					leftRotate(p);
					//Next is LL
					rightRotate(gp);
					color tmp = toCheck->color;
					toCheck->color = gp->color;
					//if (gp != _root)
						gp->color = tmp;
					toCheck = gp;
					if (*(toCheck->data) == 675 && *root->data == 550)
					{
						std::cout << "Here"<< std::endl;
						std::cout << "equal ? : " << (toCheck == _root) << std::endl;
						//exit(0);
					}
					std::cout << "toCheck is now : [" << *(toCheck->data) << "]" << std::endl;
				}
				else if (toCheck == p->left && p == gp->right)
				{
					std::cout<< "Right Left Case path from gp" << std::endl;
					std::cout<< "Rotating parent" << std::endl;
					rightRotate(p);
//					print();
					std::cout<< "Rotating gp" << std::endl;
					//Next is RR
					leftRotate(gp);
//					print();

					color tmp = toCheck->color;
					toCheck->color = gp->color;
					//if (gp != _root)
						gp->color = tmp;
					//toCheck = gp;
					toCheck = gp;
//					print();
					std::cout << "toCheck is now : [" << *(toCheck->data) << "]" << std::endl;
					//exit(0);
				}
			}
			if (go_out)
			{
				std:: cout << "exit now" << std::endl;
				print();
				exit(0);
			}
			if (toCheck != _root)
			{
				std::cout << "toCheck is not root, setting parent" << std::endl;
				p = toCheck->parent;
				if (p != _root)
				{
					std::cout << "toCheck parent is not root, setting gp and uncle" << std::endl;
					gp = toCheck->parent->parent;
					u = (gp->left == p ? gp->right : gp->left);
				}
			}
			else
				std::cout << "tocheck is root" << std::endl;
			std::cout << "End of loop -> checking condition again" << std::endl;
			//usleep(100000);
		}
		std::cout << "End of Fix" << std::endl;
	}
	*/

	/*
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
	*/
};

#endif
