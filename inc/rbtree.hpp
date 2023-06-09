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
		{ DEBUG_PRINT("node : default constuctor"); }


		~node(void)
		{
			DEBUG_PRINT("node : default destructor")
			if (data != NULL)
			{
				alloc.destroy(data);
				alloc.deallocate(data, 1);
			}
			DEBUG_PRINT("node : default destructor end")
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
		typedef T												value_type;
		typedef Compare											value_compare;
		typedef Alloc2											allocator_type;
		typedef	typename allocator_type::size_type				size_type;

		public	:
		rbtree(const value_compare &map_compare = value_compare()) :
			_root(NULL),
			_leaf(NULL),
			_comp(map_compare),
			_alloc(allocator_type()),
			_size(0)

		{
			DEBUG_PRINT("rbtree : default constuctor");
			_leaf = _alloc.allocate(1);
			_alloc.construct(_leaf, Node());
		}

		rbtree(const rbtree &src) :
			_root(src._root),
			_leaf(src._leaf),
			_comp(src._comp),
			_alloc(src._alloc),
			_size(src._size)
		{
			DEBUG_PRINT("rbtree : copy constuctor"); // non utilisee et shallow copy !!!
		}

		rbtree &operator=(const rbtree &src)
		{
			DEBUG_PRINT("rbtree : operator=")
			this->_root = src._root;
			this->_leaf = src._leaf;
			this->_comp = src._comp;
			this->_alloc = src._alloc;
			this->_size = src._size;
			return (*this);
		}

		void	swap(rbtree &x)
		{
			DEBUG_PRINT("rbtree : swap")
			Node			*tmp_root = this->_root;
			Node			*tmp_leaf = this->_leaf;
			value_compare	tmp_comp = this->_comp;
			allocator_type	tmp_alloc = this->_alloc;
			size_type		tmp_size = this->_size;

			this->_root = x._root;
			this->_leaf = x._leaf;
			this->_comp = x._comp;
			this->_alloc = x._alloc;
			this->_size = x._size;

			x._root = tmp_root;
			x._leaf = tmp_leaf;
			x._comp = tmp_comp;
			x._alloc = tmp_alloc;
			x._size = tmp_size;
		}

		size_type	getSize(void) const
		{
			DEBUG_PRINT("rbtree : getSize")
			return (_size);
		}

		~rbtree(void)
		{
			DEBUG_PRINT("rbtree : destructor")
			//destroyTree(_root);
		}

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

		//private :
		void		insert(Node	* &root, Node * parent, Node *toInsert);
		void		print(Node * const &root, unsigned int depth) const;
		void		destroyTree(Node * &root);
		void		destroyTree(void);
		void		leftRotate(Node * &root);
		void		rightRotate(Node * &root);
		void		insertFix(Node * &root);
		const Node	*findNode(const Node *root, const value_type &toFind) const;
		Node		*findNode(Node *root, const value_type &toFind); // used in deletion
		int			nbOfBlack(const Node * root) const ;
		bool		isOk(const Node * root) const ;

		const Node	*findMax(Node * root) const;
		Node		*findMax(Node * root);
		const Node	*findMin(Node * root) const;
		Node		*findMin(Node * root);

		void		transplant(Node * parent, Node *child);
		void		deleteFix(Node *x);

		Node		*lowerBound(Node *root, const value_type &toFind);
		Node		*lowerBound(const value_type &toFind);
		const Node	*lowerBound(const Node *root, const value_type &toFind) const;
		const Node	*lowerBound(const value_type &toFind) const;
		

		//Fx get_end qui renvoie la leaf et qui sera utilisee pour map.end()
		Node	*getEnd(void)
		{
			DEBUG_PRINT("rbtree : getEnd")
			return (_leaf);

		}
		const Node	*getEnd(void) const
		{
			DEBUG_PRINT("rbtree : getEnd const")
			return (_leaf);

		}

		void		createLeaf(void)
		{
			DEBUG_PRINT("rbtree : create Leaf")
			_leaf = _alloc.allocate(1);
			_alloc.construct(_leaf, Node());
		}

		size_type		max_size(void) const
		{
			DEBUG_PRINT("rbtree :  max_size")
			return (_alloc.max_size());
		}

		//MEMBER ATTRIBUTES
		private :
		Node			*_root;
		Node			*_leaf;
		value_compare	_comp;
		allocator_type	_alloc;
		size_type		_size;
	};
}

# include "rbtree.tpp"

#endif
