#ifndef CONST_NODE_ITERATOR_H
# define CONST_NODE_ITERATOR_H

# include "iterator.hpp"
# include "rbtree.hpp"
# include <cstddef>
# include "containers.hpp" // for debug
# include "node_iterator.hpp" // for construction of const_node_iterator from node_iterator

namespace ft
{
	template<typename T>
	class const_node_iterator : public ft::iterator<std::bidirectional_iterator_tag, T>
	{
		public	:
		typedef std::bidirectional_iterator_tag		iterator_category;
		typedef T									value_type;
		typedef ptrdiff_t							difference_type;
		typedef const value_type&					reference;
		typedef const value_type*					pointer;
		typedef node<T>								node_type;
		typedef const node_type*					const_node_pointer;

		private	:
		const_node_pointer		_current;
		const_node_pointer		_root;
		const_node_pointer		_end;

		public	:
		//changer les constructeur pour leur donner la end a chaque fois
		const_node_iterator(void) : _current(NULL), _root(NULL), _end(NULL)
		{
			DEBUG_PRINT("ft::CONST_node_iterator : default constructor")
		}

		//to test
		const_node_iterator(const const_node_pointer &initValue, const const_node_pointer &root, const const_node_pointer &end)
			: _current(initValue),
			_root(root),
			_end(end)
		{
			DEBUG_PRINT("ft::CONST_node_iterator : parametric constructor")
		}

		virtual ~const_node_iterator(void)
		{
			DEBUG_PRINT("ft::CONST_node_iterator : default destructor")
		}

		const_node_iterator(const const_node_iterator &src) :
			_current(src._current),
			_root(src._root),
			_end(src._end)
		{
			DEBUG_PRINT("ft::CONST_node_iterator : copy constructor")
			//*this = src;
		}

		//to test
		const const_node_pointer &base(void) const
		{
			DEBUG_PRINT("ft::CONST_node_iterator : base")
			return (_current);
		}

		const const_node_pointer &base_root(void) const
		{
			DEBUG_PRINT("ft::node_iterator : base_root")
			return (_root);
		}

		const const_node_pointer &base_end(void) const
		{
			DEBUG_PRINT("ft::node_iterator : base_end")
			return (_end);
		}

		const_node_iterator &operator=(const const_node_iterator &rhs)
		{
			DEBUG_PRINT("ft::CONST_node_iterator : operator=")
			this->_current = rhs._current;
			this->_root = rhs._root;
			this->_end = rhs._end;
			return (*this);
		}

		//From normal to const
		const_node_iterator &operator=(const node_iterator<T> &rhs)
		{
			DEBUG_PRINT("ft::CONST_node_iterator : operator= from node_iterator")
			this->_current = rhs.base();
			this->_root = rhs.base_root();
			this->_end = rhs.base_end();
			return (*this);
		}

		const_node_iterator(const node_iterator<T> &src)
		{
			DEBUG_PRINT("ft::CONST_node_iterator : copy constructor from node_iterator")
			this->_current = src.base();
			this->_root = src.base_root();
			this->_end = src.base_end();
			*this = src;
		}

		reference	operator*(void) const
		{
			DEBUG_PRINT("ft::CONST_node_iterator : operator*")
			return (*(_current->data));
		}

		pointer	operator->(void) const
		{
			DEBUG_PRINT("ft::CONST_node_iterator : operator->")
			return (_current->data);
		}

		bool		operator==(const const_node_iterator &rhs) const
		{
			DEBUG_PRINT("ft::CONST_node_iterator : operator==")
			return (this->base() == rhs.base());
		}

		bool		operator==(const node_iterator<T> &rhs) const
		{
			DEBUG_PRINT("ft::CONST_node_iterator : operator== for node_iterator")
			return (this->base() == rhs.base());
		}

		bool		operator!=(const const_node_iterator &rhs) const
		{
			DEBUG_PRINT("ft::CONST_node_iterator : operator!=")
			return (this->base() != rhs.base());
		}

		//to test
		bool		operator!=(const node_iterator<T> &rhs) const
		{
			DEBUG_PRINT("ft::CONST_node_iterator : operator!= for node_iterator")
			return (this->base() != rhs.base());
		}

		const_node_iterator &operator++(void)
		{
			DEBUG_PRINT("ft::CONST_node_iterator : pre-increment operator++")
			if (_current->data == NULL) // on return le plus petit node
			{
				_current = _root;
				while (_current->parent)
					_current = _current->parent;
				while (_current->left->data)
					_current = _current->left;
				return (*this);
			}
			if (_current->right->data != NULL) // il y a un subtree a droite -> je prend le min
			{
				_current = _current->right;
				while (_current->left->data)
					_current = _current->left;
			}
			else
			{	//tant que pas root et que je suis fils le plus gd
				/*
				const_node_pointer save_end = _current->right; // save end si jamais on etait le node le plus gd du tree
				*/
				const_node_pointer save_end = _end; // save end si jamais on etait le node le plus gd du tree
				while (_current->parent && _current == _current->parent->right)
					_current = _current->parent; // je remonte
				if (_current->parent == NULL) // je suis remonte jusqu'au root, ie je suis le plus gd -> je renvoie end
					_current = save_end;
				else // Je renvoie mon parent
					_current = _current->parent;
			}
			return *this;
		}

		const_node_iterator &operator--(void)
		{
			DEBUG_PRINT("ft::CONST_node_iterator : pre-decrement operator--")
			if (_current->data == NULL) // on return le plus grand node
			{
				_current = _root;
				while (_current->parent)
					_current = _current->parent;
				while (_current->right->data)
					_current = _current->right;
				return (*this);
			}
			if (_current->left->data != NULL)
			{
				_current = _current->left;
				while (_current->right->data)
					_current = _current->right;
			}
			else
			{ // travail a faire pour aller a la node la plus a droite
				const_node_pointer save_end = _end;
				/*
				const_node_pointer save_end = _current;
				while (save_end->parent)
					save_end = save_end->parent;
				while (save_end->right->data)
					save_end = save_end->right;
				save_end = save_end->right;
				// save_end vaut end;
				*/

				while (_current->parent && _current == _current->parent->left)
					_current = _current->parent;
				if (_current->parent == NULL)
					_current = save_end;
				else
					_current = _current->parent;
			}
			return *this;
		}

		const_node_iterator operator++(int)
		{
			DEBUG_PRINT("ft::CONST_node_iterator : post-increment operator++")
			const_node_iterator	tmp(_current, _root, _end);
			this->operator++();
			return (tmp);
		}

		const_node_iterator operator--(int)
		{
			DEBUG_PRINT("ft::CONST_node_iterator : post-increment operator--")
			const_node_iterator	tmp(_current, _root, _end);
			this->operator--();
			return (tmp);
		}
	};
}

#endif

