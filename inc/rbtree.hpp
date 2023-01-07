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

		void	leftRotate(Node * &root);
		void	rightRotate(Node * &root);

		private	:
		void	insert(Node	* &root, Node * parent, Node *toInsert);
		void	print(Node * const &root, unsigned int depth) const;
		void	destroyTree(Node * &root);
		void	insertFix(Node * &root);

		//MEMBER ATTRIBUTES
		private :
		Node	*_root;
	};
}

# include "rbtree.tpp"

#endif
