#ifndef RBTREE_T
# define RBTREE_T

# ifndef RBTREE_H
#  error __FILE__ should only be included via rbtree.hpp
# endif

#include <unistd.h>

namespace ft
{
	//this is the save !!!!
	template<class T, class Compare, class Alloc, class Node, class Alloc2>
	void	rbtree<T, Compare, Alloc, Node, Alloc2>::insert(const value_type &val)
	{
		DEBUG_PRINT("rbtree : insert")
		try
		{
			Node *newNode = _alloc.allocate(1);
			_alloc.construct(newNode, Node());

			Node *newLeaf_1 = _alloc.allocate(1);
			_alloc.construct(newLeaf_1, Node());

			Node *newLeaf_2 = _alloc.allocate(1);
			_alloc.construct(newLeaf_2, Node());

			newNode->setData(val);
			newNode->left = newLeaf_1;
			//newNode->left = _leaf;
			newNode->left->parent = newNode;
			newNode->left->color = BLACK;
			newNode->right = newLeaf_2;
			//newNode->right = _leaf;
			newNode->right->parent = newNode;
			newNode->right->color = BLACK;
			insert(_root, NULL, newNode);
			_size++;
		}
		catch (std::exception &e)
		{
			DEBUG_PRINT("rbtree : insert exception catch")
			throw;
		}
		DEBUG_PRINT("rbtree : insert end")
	}


	template<class T, class Compare, class Alloc, class Node, class Alloc2>
	Node * rbtree<T, Compare, Alloc, Node, Alloc2>::getRoot(void)
	{
		DEBUG_PRINT("rbtree : get root")
		return _root;
	}

	template<class T, class Compare, class Alloc, class Node, class Alloc2>
	const Node * rbtree<T, Compare, Alloc, Node, Alloc2>::getRoot(void) const
	{
		DEBUG_PRINT("rbtree : get root : const version")
		return _root;
	}

	template<class T, class Compare, class Alloc, class Node, class Alloc2>
	void	rbtree<T, Compare, Alloc, Node, Alloc2>::print(void) const
	{
		print(_root, 0);
	}

	template<class T, class Compare, class Alloc, class Node, class Alloc2>
	void	rbtree<T, Compare, Alloc, Node, Alloc2>::insert(Node * &root, Node *parent, Node *toInsert)
	{
		DEBUG_PRINT("rbtree : insert true")
		//std::cerr << "size is :" << _size << std::endl;
		if (root == NULL) // cas ou _root est null, ie l'arbre est vide
		{
			DEBUG_PRINT("rbtree : insert true begin 1")
			root = toInsert;
			root->color = BLACK;
			DEBUG_PRINT("rbtree : insert true end 1")
			return ;
		}
		if (root->data == NULL) // on est sur une feuille
		{
			DEBUG_PRINT("rbtree : insert true begin 2")
			_alloc.destroy(root);// > plus besoin avec leaf
			_alloc.deallocate(root, 1);// > plus besoin avec leaf
			DEBUG_PRINT("rbtree : insert true 2 after deletion")
			root = toInsert;
			root->parent = parent;
			if (_size < 3)
			{
				_root->color = BLACK;
				return;
			}
			else if (root->parent != NULL && root->parent->color == RED)
			{
				insertFix(root);
			}
			DEBUG_PRINT("rbtree : insert true end 2")
			return ;
		}
		//if (*(toInsert->data) < *(root->data))
		if (_comp(*(toInsert->data), *(root->data)))
		{
			//std::cerr << "going left" << std::endl;
			insert(root->left, root, toInsert);
		}
		else
		{
			//std::cerr << "going right" << std::endl;
			insert(root->right, root, toInsert);
		}
	}

	template<class T, class Compare, class Alloc, class Node, class Alloc2>
	void	rbtree<T, Compare, Alloc, Node, Alloc2>::print(Node * const &root, unsigned int depth) const
	{
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
			}
			if (root->right == NULL)
			{
				std::cout <<  "KO Right child!!!";
			}
			std::cout << *(root->data);
		}
		if (root->parent == NULL && root != _root)
		{
			std::cout <<  "KO parent!!!";
		}
		std::cout << "\x1b[0m]"<< std::endl;
		print(root->left, depth + 1);
	}

	template<class T, class Compare, class Alloc, class Node, class Alloc2>
	void	rbtree<T, Compare, Alloc, Node, Alloc2>::leftRotate(Node * &root)
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


	template<class T, class Compare, class Alloc, class Node, class Alloc2>
	void	rbtree<T, Compare, Alloc, Node, Alloc2>::rightRotate(Node * &root)
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


	template<class T, class Compare, class Alloc, class Node, class Alloc2>
	void	rbtree<T, Compare, Alloc, Node, Alloc2>::destroyTree(Node * &root)
	{
		//if (root == NULL || root->data == NULL)
		if (root == NULL)// -> different avec leaf (ie solution juste au dessus)
			return;
		destroyTree(root->left);
		destroyTree(root->right);
		_alloc.destroy(root);
		_alloc.deallocate(root, 1);
	}

	template<class T, class Compare, class Alloc, class Node, class Alloc2>
	void	rbtree<T, Compare, Alloc, Node, Alloc2>::destroyTree(void)
	{
		DEBUG_PRINT("rbtree : destroy tree")
		destroyTree(_root);
		_root = NULL;
		_size = 0;
		//desallouer la leaf
		_alloc.destroy(_leaf);
		_alloc.deallocate(_leaf, 1);
	}

	template<class T, class Compare, class Alloc, class Node, class Alloc2>
	const Node	*rbtree<T, Compare, Alloc, Node, Alloc2>::findNode(const value_type &toFind) const
	{
		if (_root == NULL)
			return (NULL);
		return (findNode(_root, toFind));

	}

	template<class T, class Compare, class Alloc, class Node, class Alloc2>
	const Node	*rbtree<T, Compare, Alloc, Node, Alloc2>::findNode(const Node * root, const value_type &toFind) const
	{
		if (root->data == NULL)
			return (NULL);
		if (! _comp(toFind, *(root->data)) && !_comp(*(root->data), toFind))
			return (root);
		if (_comp(toFind, *(root->data)))
			return (findNode(root->left, toFind));
		else
			return (findNode(root->right, toFind));
	}

	//non-const version used for deletion
	template<class T, class Compare, class Alloc, class Node, class Alloc2>
	Node	*rbtree<T, Compare, Alloc, Node, Alloc2>::findNode(const value_type &toFind)
	{
		if (_root == NULL)
			return (NULL);
		return (findNode(_root, toFind));

	}

	//non-const version used for deletion
	template<class T, class Compare, class Alloc, class Node, class Alloc2>
	Node	*rbtree<T, Compare, Alloc, Node, Alloc2>::findNode(Node * root, const value_type &toFind)
	{
		if (root->data == NULL)
			return (NULL);
		if (! _comp(toFind, *(root->data)) && !_comp(*(root->data), toFind))
			return (root);
		if (_comp(toFind, *(root->data)))
			return (findNode(root->left, toFind));
		else
			return (findNode(root->right, toFind));
	}

	template<class T, class Compare, class Alloc, class Node, class Alloc2>
	int		rbtree<T, Compare, Alloc, Node, Alloc2>::nbOfBlack(const Node * root) const
	{
		if (root->data == NULL)
			return (1);
		if (root->color == BLACK)
			return (1 + nbOfBlack(root->left));
		else
			return (nbOfBlack(root->left));
	}

	template<class T, class Compare, class Alloc, class Node, class Alloc2>
	bool rbtree<T, Compare, Alloc, Node, Alloc2>::isOk(const Node * root) const
	{
		if (root->data == NULL)
			return (true);
		bool leftStatus = nbOfBlack(root->left);
		bool rightStatus = nbOfBlack(root->right);
		if (leftStatus != rightStatus)
		{
			std::cout << "Not same nb of black for left and right for : [" << *(root->data) << "] !" << std::endl;
			return (false);
		}
		if (root != _root && root->color == RED && root->parent->color == RED)
		{
			std::cout << "[" << *(root->data) << "] is RED and [" << *(root->parent->data) << "] is RED !" << std::endl;
			return (false);
		}
		return(isOk(root->left) && isOk(root->right));
	}

	template<class T, class Compare, class Alloc, class Node, class Alloc2>
	bool rbtree<T, Compare, Alloc, Node, Alloc2>::isOk(void) const
	{
		if (_root == NULL)
			return (true);
		return (isOk(_root));
	}

	template<class T, class Compare, class Alloc, class Node, class Alloc2>
	const Node *rbtree<T, Compare, Alloc, Node, Alloc2>::findMax(Node * root) const
	{
		if (root->right->data == NULL)
			return (root);
		return (findMax(root->right));
	}

	template<class T, class Compare, class Alloc, class Node, class Alloc2>
	const Node *rbtree<T, Compare, Alloc, Node, Alloc2>::findMax(void) const
	{
		DEBUG_PRINT("rbtree : findMax const")
		if (_root == NULL)
			return (NULL);
		if (_root->right == NULL)
			return (_root);
		return (findMax(_root));
	}

	template<class T, class Compare, class Alloc, class Node, class Alloc2>
	Node *rbtree<T, Compare, Alloc, Node, Alloc2>::findMax(Node * root)
	{
		if (root->right->data == NULL)
			return (root);
		return (findMax(root->right));
	}

	template<class T, class Compare, class Alloc, class Node, class Alloc2>
	Node *rbtree<T, Compare, Alloc, Node, Alloc2>::findMax(void)
	{
		DEBUG_PRINT("rbtree : findMax")
		if (_root == NULL)
		{
			std::cout << "_root is NULL" << std::endl;
			return (NULL);
		}
		if (_root->right == NULL)
		{
			std::cout << "_root->right is NULL" << std::endl;
			return (_root);
		}
		return (findMax(_root));
	}

	template<class T, class Compare, class Alloc, class Node, class Alloc2>
	const Node *rbtree<T, Compare, Alloc, Node, Alloc2>::findMin(Node * root) const
	{
		DEBUG_PRINT("rbtree : findMin const root version")
		if (root->left->data == NULL)
			return (root);
		return (findMin(root->left));
	}

	template<class T, class Compare, class Alloc, class Node, class Alloc2>
	const Node *rbtree<T, Compare, Alloc, Node, Alloc2>::findMin(void) const
	{
		DEBUG_PRINT("rbtree : findMin const")
		if (_root == NULL)
			return (NULL);
		if (_root->left == NULL)
			return (_root);
		return (findMin(_root));
	}

	template<class T, class Compare, class Alloc, class Node, class Alloc2>
	Node *rbtree<T, Compare, Alloc, Node, Alloc2>::findMin(Node * root)
	{
		DEBUG_PRINT("rbtree : findMin root version")
		if (root->left->data == NULL)
		{
			return (root);
		}
		return (findMin(root->left));
	}

	template<class T, class Compare, class Alloc, class Node, class Alloc2>
	Node *rbtree<T, Compare, Alloc, Node, Alloc2>::findMin(void)
	{
		DEBUG_PRINT("rbtree : findMin")
		if (_root == NULL)
			return (NULL);
		if (_root->left == NULL)
			return (_root);
		return (findMin(_root));
	}

	template<class T, class Compare, class Alloc, class Node, class Alloc2>
	void	rbtree<T, Compare, Alloc, Node, Alloc2>::transplant(Node * parent, Node *child)
	{
		//changing child parent
		child->parent = parent->parent;
		//changing parent->parent child
		if (parent == _root)
			_root = child;
		else if (parent->parent->left == parent)
			parent->parent->left = child;
		else
			parent->parent->right = child;
	}

	template<class T, class Compare, class Alloc, class Node, class Alloc2>
	void rbtree<T, Compare, Alloc, Node, Alloc2>::deleteNode(const value_type &toDelete)
	{
		Node *target = findNode(toDelete);
		Node *x;
		Node *y;

		if (_root == NULL)
			return ;
		if (findNode(toDelete) == NULL)
		{
			//std::cout << "didn't find node to delete" << std::endl;
			return ;
		}
		color originalColor = target->color;
		if (target->left->data == NULL)
		{
			x = target->right;
			transplant(target, target->right);
			_alloc.destroy(target->left);// -> plus besoin leaf
			_alloc.deallocate(target->left, 1);// -> plus besoin leaf
		}
		else if (target->right->data == NULL)
		{
			x = target->left;
			transplant(target, target->left);
			_alloc.destroy(target->right);// -> plus besoin leaf
			_alloc.deallocate(target->right, 1);// -> plus besoin leaf
		}
		else
		{
			y = findMin(target->right); // plus petit superieur a target
			originalColor = y->color;
			x = y->right; // node droit du plus petit sup a target
			if (y->parent == target)
				x->parent = y;
			else
			{
				transplant(y, y->right);
				y->right = target->right;
				y->right->parent = y;
			}
			transplant(target, y);
			_alloc.destroy(y->left);// -> plub besoin leaf
			_alloc.deallocate(y->left, 1);// -> plub besoin leaf
			y->left = target->left;
			y->left->parent = y;
			y->color = target->color; // Not sure ?

		}
		if (originalColor == BLACK)
			deleteFix(x);
		_alloc.destroy(target);
		_alloc.deallocate(target, 1); // 0 ?????
		_size--;
		if (_size == 0)
		{
			_alloc.destroy(_root);
			_alloc.deallocate(_root, 1); // 0 ?????
			_root = NULL;
			_leaf->color = BLACK;
		}
	}

	template<class T, class Compare, class Alloc, class Node, class Alloc2>
	void rbtree<T, Compare, Alloc, Node, Alloc2>::deleteFix(Node *x)
	{
		Node *w;

		while (x != _root && x->color == BLACK)
		{
			if (x == x->parent->left)
			{
				w = x->parent->right;
				if (w->color == RED)
				{
					w->color = BLACK;
					x->parent->color = RED;
					leftRotate(x->parent);
					w = x->parent->right;
				}
				if (w->right->color == BLACK && w->left->color == BLACK)
				{
					w->color = RED;
					x = x->parent;
				}
				else
				{
					if (w->right->color == BLACK)
					{
						w->left->color = BLACK;
						w->color = RED;
						rightRotate(w);
						w = x->parent->right;
					}
					w->color = x->parent->color;
					x->parent->color = BLACK;
					w->right->color = BLACK;
					leftRotate(x->parent);
					x = _root;
				}
			}
			else
			{
				w = x->parent->left;
				if (w->color == RED)
				{
					w->color = BLACK;
					x->parent->color = RED;
					rightRotate(x->parent);
					w = x->parent->left;
				}
				if (w->right->color == BLACK && w->left->color == BLACK) // ???
				{
					w->color = RED;
					x = x->parent;
				}
				else
				{
					if (w->left->color == BLACK)
					{
						w->right->color = BLACK;
						w->color = RED;
						leftRotate(w);
						w = x->parent->left;
					}
					w->color = x->parent->color;
					x->parent->color = BLACK;
					w->left->color = BLACK;
					rightRotate(x->parent);
					x = _root;
				}
			}
		}
		x->color = BLACK;
	}

	template<class T, class Compare, class Alloc, class Node, class Alloc2>
	void	rbtree<T, Compare, Alloc, Node, Alloc2>::insertFix(Node * &root)
	{
		DEBUG_PRINT("rbtree : insert fix")
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
			DEBUG_PRINT("rbtree : insert fix loop end")
		}
		DEBUG_PRINT("rbtree : insert fix end")
	}

	template<class T, class Compare, class Alloc, class Node, class Alloc2>
	Node	*rbtree<T, Compare, Alloc, Node, Alloc2>::lowerBound(const value_type &toFind)
	{
		DEBUG_PRINT("rbtree : lowerBound")
		if (_root == NULL)
			return (NULL);
		return (lowerBound(_root, toFind));
	}

	template<class T, class Compare, class Alloc, class Node, class Alloc2>
	Node	*rbtree<T, Compare, Alloc, Node, Alloc2>::lowerBound(Node * root, const value_type &toFind)
	{
		if (root->data == NULL)
			return (NULL);

		Node *	leftResult = lowerBound(root->left, toFind);
		Node *	rightResult = lowerBound(root->right, toFind);

		if (leftResult)
			return (leftResult);
		if (! _comp(*(root->data), toFind))
			return (root);
		return (rightResult);
	}

	template<class T, class Compare, class Alloc, class Node, class Alloc2>
	const Node	*rbtree<T, Compare, Alloc, Node, Alloc2>::lowerBound(const value_type &toFind) const
	{
		DEBUG_PRINT("rbtree : lowerBound")
		if (_root == NULL)
			return (NULL);
		return (lowerBound(_root, toFind));
	}

	template<class T, class Compare, class Alloc, class Node, class Alloc2>
	const Node	*rbtree<T, Compare, Alloc, Node, Alloc2>::lowerBound(const Node * root, const value_type &toFind) const
	{
		if (root->data == NULL)
			return (NULL);

		const Node *	leftResult = lowerBound(root->left, toFind);
		const Node *	rightResult = lowerBound(root->right, toFind);

		if (leftResult)
			return (leftResult);
		if (! _comp(*(root->data), toFind))
			return (root);
		return (rightResult);
	}

};

#endif
