#ifndef RBTREE_H
# define RBTREE_H

#include <iostream> // For print
#include "containers.hpp" // For debug

typedef enum {RED, BLACK} color;

namespace ft
{
	template <class T>
	struct node
	{
		typedef T		value_type;

		node(void) : parent(NULL), left(NULL), right(NULL), data(NULL), color(RED)
		{};
		~node(void) { delete data; }
		void setData(const value_type &initValue) { data = new value_type(initValue); }

		node		*parent;
		node		*left;
		node		*right;
		value_type	*data; // To allow leaves to have a null pointer
		color		color;
	};

	template <class T>
	void swapColor(node<T> *lhs, node<T> *rhs)
	{
		color tmp = lhs->color;

		lhs->color = rhs->color;
		rhs->color = tmp;
	}

	template <class T, class Node = ft::node<T> >
	class rbtree
	{
		public	:
		typedef T		value_type;

		public	:
		rbtree(void) : _root(NULL) {}
		~rbtree(void) { destroyTree(_root); }

		//MEMBER FX
		void	insert(const value_type &val);
		Node * &getRoot(void);
		void	print(void) const;
		Node	*findNode(const value_type &toFind);
		bool	isOk(void);


		private	:
		void	insert(Node	* &root, Node * parent, Node *toInsert);
		void	print(Node * const &root, unsigned int depth) const;
		void	destroyTree(Node * &root);
		void	leftRotate(Node * &root);
		void	rightRotate(Node * &root);
		void	insertFix(Node * &root);
		Node	*findNode(Node * &root, const value_type &toFind);
		int		nbOfBlack(Node * &root) const ;
		bool	isOk(Node * &root);

		//MEMBER ATTRIBUTES
		private :
		Node	*_root;
	};
}

# include "rbtree.tpp"

#endif
