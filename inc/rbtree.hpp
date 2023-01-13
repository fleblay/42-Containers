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

		node(void) : parent(NULL), left(NULL), right(NULL), data(NULL), color(RED), alloc(allocator_type())
		{};
		//~node(void) { delete data; }
		//void setData(const value_type &initValue) { data = new value_type(initValue); }
		~node(void)
		{
			alloc.destroy(data);
			alloc.deallocate(data, 1);
		}
		void setData(const value_type &initValue)
		{
			data = alloc.allocate(1);
			alloc.construct(data, initValue);
		}

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

	template <class T,
			 class Compare, // en fait ici une value_compare de la map quand instanciee depuis la map
			 class Alloc = std::allocator<T>,
			 class Node = ft::node<T, Alloc>,
			 class Alloc2 = std::allocator<Node >
			 >
	class rbtree
	{
		public	:
		typedef T					value_type;
		typedef Compare				value_compare;
		typedef Alloc2				allocator_type;

		public	:
		rbtree(const value_compare &map_compare = value_compare()) :
			_root(NULL),
			_comp(map_compare),
			alloc(allocator_type())
		//surchare de == a faire !
		{ DEBUG_PRINT("rbtree : default constuctor"); }
		~rbtree(void) { destroyTree(_root); }

		//MEMBER FX
		void		insert(const value_type &val);
		const Node	* getRoot(void) const;
		Node		* getRoot(void);
		void		print(void) const;
		const Node	*findNode(const value_type &toFind) const;
		Node		*findNode(const value_type &toFind); // used in deletion
		bool		isOk(void) const;
		const Node	*findMax(void) const;
		Node		*findMax(void);
		const Node	*findMin(void) const;
		Node		*findMin(void);
		void		deleteNode(const value_type &toDelete);

		void		insert(Node	* &root, Node * parent, Node *toInsert);
		void		print(Node * const &root, unsigned int depth) const;
		void		destroyTree(Node * &root);
		void		leftRotate(Node * &root);
		void		rightRotate(Node * &root);
		void		insertFix(Node * &root);
		const Node	*findNode(Node * &root, const value_type &toFind) const;
		Node		*findNode(Node * &root, const value_type &toFind); // used in deletion
		int			nbOfBlack(const Node * root) const ;
		bool		isOk(const Node * root) const ;

		const Node	*findMax(Node * root) const;
		Node		*findMax(Node * root);
		const Node	*findMin(Node * root) const;
		Node		*findMin(Node * root);

		void		transplant(Node * parent, Node *child);
		void		deleteFix(Node *x);

		//MEMBER ATTRIBUTES
		private :
		Node			*_root;
		value_compare	_comp;
		allocator_type	alloc;
	};
}

# include "rbtree.tpp"

#endif
