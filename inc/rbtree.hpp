#ifndef RBTREE_H
# define RBTREE_H

#include <iostream> // For print
#include "containers.hpp" // For debug

typedef enum {RED, BLACK} color;

namespace ft
{
	template <class T, class Alloc = std::allocator<T> >
	struct node
	{
		typedef T		value_type;
		typedef Alloc	allocator_type;

		node(void) : parent(NULL), left(NULL), right(NULL), data(NULL), color(RED)
		{};
		~node(void) { delete data; }
		void setData(const value_type &initValue) { data = new value_type(initValue); }

		node			*parent;
		node			*left;
		node			*right;
		value_type		*data; // To allow leaves to have a null pointer
		color			color;
		allocator_type	alloc;
	};

	template <class T, class Alloc>
	void swapColor(node<T, Alloc> *lhs, node<T, Alloc> *rhs)
	{
		color tmp = lhs->color;

		lhs->color = rhs->color;
		rhs->color = tmp;
	}

	template <class T, class Compare, class Alloc = std::allocator<T>, class Node = ft::node<T, Alloc> >
	class rbtree
	{
		public	:
		typedef T			value_type;
		typedef Compare		key_compare;

		public	:
		rbtree(void) : _root(NULL), _comp(key_compare()) {}
		~rbtree(void) { destroyTree(_root); }

		//MEMBER FX
		void	insert(const value_type &val);
		Node * &getRoot(void);
		void	print(void) const;
		Node	*findNode(const value_type &toFind);
		bool	isOk(void) const;
		Node *findMax(void);
		Node *findMin(void);
		void	deleteNode(const value_type &toDelete);

		private	:
		void	insert(Node	* &root, Node * parent, Node *toInsert);
		void	print(Node * const &root, unsigned int depth) const;
		void	destroyTree(Node * &root);
		void	leftRotate(Node * &root);
		void	rightRotate(Node * &root);
		void	insertFix(Node * &root);
		Node	*findNode(Node * &root, const value_type &toFind);
		int		nbOfBlack(const Node * root) const ;
		bool	isOk(const Node * root) const ;

		Node *findMax(Node * root);
		Node *findMin(Node * root);

		void	transplant(Node * parent, Node *child);
		void	deleteFix(Node *x);

		//MEMBER ATTRIBUTES
		private :
		Node		*_root;
		key_compare	_comp;
	};
}

# include "rbtree.tpp"

#endif
