#ifndef NODE_ITERATOR_H
# define NODE_ITERATOR_H

# include "iterator.hpp"
# include "rbtree.hpp"
# include <cstddef>
# include "containers.hpp" // for debug

namespace ft
{
	template<typename T>
	class const_node_iterator;

	template<typename T>
	class node_iterator : public ft::iterator<std::bidirectional_iterator_tag, T>
	{
		public	:
		typedef std::bidirectional_iterator_tag		iterator_category;
		typedef T									value_type;
		typedef ptrdiff_t							difference_type;
		typedef value_type&							reference;
		typedef value_type*							pointer;
		typedef node<T>								node_type;
		typedef node_type*							node_pointer;

		private	:
		node_pointer	_current;
		node_pointer	_root;
		node_pointer	_end;

		public	:
		//changer les constructeur pour leur donner la end a chaque fois et le root !!!	
		node_iterator(void) : _current(NULL), _root(NULL), _end(NULL)
		{
			DEBUG_PRINT("ft::node_iterator : default constructor")
		}

		//to test
		node_iterator(const node_pointer &initValue, const node_pointer &root, const node_pointer &end)
			: _current(initValue),
			_root(root),
			_end(end)
		{
			DEBUG_PRINT("ft::node_iterator : parametric constructor")
		}

		virtual ~node_iterator(void)
		{
			DEBUG_PRINT("ft::node_iterator : default destructor")
		}

		const node_pointer &base(void) const
		{
			DEBUG_PRINT("ft::node_iterator : base")
			return (_current);
		}

		const node_pointer &base_root(void) const
		{
			DEBUG_PRINT("ft::node_iterator : base_root")
			return (_root);
		}

		const node_pointer &base_end(void) const
		{
			DEBUG_PRINT("ft::node_iterator : base_end")
			return (_end);
		}

		/*
		node_iterator(const node_iterator &src)
		{
			DEBUG_PRINT("ft::node_iterator : copy constructor")
			*this = src;
		}
		*/
		node_iterator(const node_iterator &src) :
			_current(src._current),
			_root(src._root),
			_end(src._end)
		{
			DEBUG_PRINT("ft::CONST_node_iterator : copy constructor")
			//*this = src;
		}

		node_iterator &operator=(const node_iterator &rhs)
		{
			DEBUG_PRINT("ft::node_iterator : operator=")
			this->_current = rhs._current;
			this->_root = rhs._root;
			this->_end = rhs._end;
			return (*this);
		}

		reference	operator*(void) const
		{
			DEBUG_PRINT("ft::node_iterator : operator*")
			return (*(_current->data));
		}

		pointer	operator->(void) const
		{
			DEBUG_PRINT("ft::node_iterator : operator->")
			return (_current->data);
		}

		bool		operator==(const node_iterator &rhs) const
		{
			DEBUG_PRINT("ft::node_iterator : operator==")
			return (this->base() == rhs.base());
		}

		bool		operator==(const const_node_iterator<T> &rhs) const
		{
			DEBUG_PRINT("ft::node_iterator : operator== for CONST_node_iterator")
			return (this->base() == rhs.base());
		}

		bool		operator!=(const node_iterator &rhs) const
		{
			DEBUG_PRINT("ft::node_iterator : operator!=")
			return (this->base() != rhs.base());
		}

		bool		operator!=(const const_node_iterator<T> &rhs) const
		{
			DEBUG_PRINT("ft::node_iterator : operator!= for CONST_node_iterator")
			return (this->base() != rhs.base());
		}

		node_iterator &operator++(void)
		{
			DEBUG_PRINT("ft::node_iterator : pre-increment operator++")
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
				node_pointer save_end = _current->right; // save end si jamais on etait le node le plus gd du tree
				*/
				node_pointer save_end = _end; // save end si jamais on etait le node le plus gd du tree
				while (_current->parent && _current == _current->parent->right)
					_current = _current->parent; // je remonte
				if (_current->parent == NULL)
				{
					// je suis remonte jusqu'au root, ie je suis le plus gd -> je renvoie end
					//std::cout << "Using save end" << std::endl;
					_current = save_end;

				}
				else
				{
					// Je renvoie mon parent
					//std::cout << "Using parent" << std::endl;
					_current = _current->parent;
				}
			}
			return *this;
		}

		node_iterator &operator--(void)
		{
			DEBUG_PRINT("ft::node_iterator : pre-decrement operator--")
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
				node_pointer save_end = _end;

				while (_current->parent && _current == _current->parent->left)
					_current = _current->parent;
				if (_current->parent == NULL)
					_current = save_end;
				else
					_current = _current->parent;
			}
			return *this;
		}

		node_iterator operator++(int)
		{
			DEBUG_PRINT("ft::node_iterator : post-increment operator++")
			node_iterator	tmp(_current, _root, _end);
			this->operator++();
			return (tmp);
		}

		node_iterator operator--(int)
		{
			DEBUG_PRINT("ft::node_iterator : post-increment operator--")
			node_iterator	tmp(_current, _root, _end);
			this->operator--();
			return (tmp);
		}
	};
}

#endif
