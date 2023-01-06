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

		node(const T &initValue = value_type()) : parent(NULL), left(NULL), right(NULL), data(initValue), color(RED) {};
		~node(void) {};

		node		*parent;
		node		*left;
		node		*right;
		value_type	data;
		color		color;
	};

	template <class T, class Node = ft::node<T> >
	class rbtree
	{
		public	:
		typedef T		value_type;

		public	:
		rbtree(void) : _root(NULL) {};
		~rbtree(void) {};

		//MEMBER FX
		void	insert(const T &val);
		Node * &getRoot(void);
		void	print(void) const;

		void	leftRotate(Node * &root);
		private	:
		void	insert(Node	* &root, Node * parent, Node *toInsert);
		void	print(Node * const &root, unsigned int depth) const;

		//MEMBER ATTRIBUTES
		private :
		Node	*_root;
	};
}

# include "rbtree.tpp"

#endif
