# 1 "raw_src/stl_vector.h"
# 1 "<built-in>" 1
# 1 "<built-in>" 3
# 404 "<built-in>" 3
# 1 "<command line>" 1
# 1 "<built-in>" 2
# 1 "raw_src/stl_vector.h" 2
# 59 "raw_src/stl_vector.h"
# 1 "/usr/bin/../lib/gcc/x86_64-linux-gnu/11/../../../../include/c++/11/bits/stl_iterator_base_funcs.h" 1 3
# 63 "/usr/bin/../lib/gcc/x86_64-linux-gnu/11/../../../../include/c++/11/bits/stl_iterator_base_funcs.h" 3

# 1 "/usr/bin/../lib/gcc/x86_64-linux-gnu/11/../../../../include/c++/11/bits/concept_check.h" 1 3
# 34 "/usr/bin/../lib/gcc/x86_64-linux-gnu/11/../../../../include/c++/11/bits/concept_check.h" 3

# 1 "/usr/bin/../lib/gcc/x86_64-linux-gnu/11/../../../../include/x86_64-linux-gnu/c++/11/bits/c++config.h" 1 3
# 278 "/usr/bin/../lib/gcc/x86_64-linux-gnu/11/../../../../include/x86_64-linux-gnu/c++/11/bits/c++config.h" 3
namespace std
{
  typedef long unsigned int size_t;
  typedef long int ptrdiff_t;


  typedef decltype(nullptr) nullptr_t;

}
# 300 "/usr/bin/../lib/gcc/x86_64-linux-gnu/11/../../../../include/x86_64-linux-gnu/c++/11/bits/c++config.h" 3
namespace std
{
  inline namespace __cxx11 __attribute__((__abi_tag__ ("cxx11"))) { }
}
namespace __gnu_cxx
{
  inline namespace __cxx11 __attribute__((__abi_tag__ ("cxx11"))) { }
}
# 586 "/usr/bin/../lib/gcc/x86_64-linux-gnu/11/../../../../include/x86_64-linux-gnu/c++/11/bits/c++config.h" 3
# 1 "/usr/bin/../lib/gcc/x86_64-linux-gnu/11/../../../../include/x86_64-linux-gnu/c++/11/bits/os_defines.h" 1 3
# 39 "/usr/bin/../lib/gcc/x86_64-linux-gnu/11/../../../../include/x86_64-linux-gnu/c++/11/bits/os_defines.h" 3
# 1 "/usr/include/features.h" 1 3 4
# 392 "/usr/include/features.h" 3 4
# 1 "/usr/include/features-time64.h" 1 3 4
# 20 "/usr/include/features-time64.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/wordsize.h" 1 3 4
# 21 "/usr/include/features-time64.h" 2 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/timesize.h" 1 3 4
# 19 "/usr/include/x86_64-linux-gnu/bits/timesize.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/wordsize.h" 1 3 4
# 20 "/usr/include/x86_64-linux-gnu/bits/timesize.h" 2 3 4
# 22 "/usr/include/features-time64.h" 2 3 4
# 393 "/usr/include/features.h" 2 3 4
# 464 "/usr/include/features.h" 3 4
# 1 "/usr/include/stdc-predef.h" 1 3 4
# 465 "/usr/include/features.h" 2 3 4
# 486 "/usr/include/features.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 1 3 4
# 559 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/wordsize.h" 1 3 4
# 560 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 2 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/long-double.h" 1 3 4
# 561 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 2 3 4
# 487 "/usr/include/features.h" 2 3 4
# 510 "/usr/include/features.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/gnu/stubs.h" 1 3 4
# 10 "/usr/include/x86_64-linux-gnu/gnu/stubs.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/gnu/stubs-64.h" 1 3 4
# 11 "/usr/include/x86_64-linux-gnu/gnu/stubs.h" 2 3 4
# 511 "/usr/include/features.h" 2 3 4
# 40 "/usr/bin/../lib/gcc/x86_64-linux-gnu/11/../../../../include/x86_64-linux-gnu/c++/11/bits/os_defines.h" 2 3
# 587 "/usr/bin/../lib/gcc/x86_64-linux-gnu/11/../../../../include/x86_64-linux-gnu/c++/11/bits/c++config.h" 2 3


# 1 "/usr/bin/../lib/gcc/x86_64-linux-gnu/11/../../../../include/x86_64-linux-gnu/c++/11/bits/cpu_defines.h" 1 3
# 590 "/usr/bin/../lib/gcc/x86_64-linux-gnu/11/../../../../include/x86_64-linux-gnu/c++/11/bits/c++config.h" 2 3
# 36 "/usr/bin/../lib/gcc/x86_64-linux-gnu/11/../../../../include/c++/11/bits/concept_check.h" 2 3
# 65 "/usr/bin/../lib/gcc/x86_64-linux-gnu/11/../../../../include/c++/11/bits/stl_iterator_base_funcs.h" 2 3
# 1 "/usr/bin/../lib/gcc/x86_64-linux-gnu/11/../../../../include/c++/11/debug/assertions.h" 1 3
# 66 "/usr/bin/../lib/gcc/x86_64-linux-gnu/11/../../../../include/c++/11/bits/stl_iterator_base_funcs.h" 2 3

namespace std __attribute__ ((__visibility__ ("default")))
{




  template <typename> struct _List_iterator;
  template <typename> struct _List_const_iterator;


  template<typename _InputIterator>
    inline constexpr
    typename iterator_traits<_InputIterator>::difference_type
    __distance(_InputIterator __first, _InputIterator __last,
               input_iterator_tag)
    {



      typename iterator_traits<_InputIterator>::difference_type __n = 0;
      while (__first != __last)
 {
   ++__first;
   ++__n;
 }
      return __n;
    }

  template<typename _RandomAccessIterator>
    inline constexpr
    typename iterator_traits<_RandomAccessIterator>::difference_type
    __distance(_RandomAccessIterator __first, _RandomAccessIterator __last,
               random_access_iterator_tag)
    {



      return __last - __first;
    }



  template<typename _Tp>
    ptrdiff_t
    __distance(std::_List_iterator<_Tp>,
        std::_List_iterator<_Tp>,
        input_iterator_tag);

  template<typename _Tp>
    ptrdiff_t
    __distance(std::_List_const_iterator<_Tp>,
        std::_List_const_iterator<_Tp>,
        input_iterator_tag);
# 135 "/usr/bin/../lib/gcc/x86_64-linux-gnu/11/../../../../include/c++/11/bits/stl_iterator_base_funcs.h" 3
  template<typename _InputIterator>
    inline
    typename iterator_traits<_InputIterator>::difference_type
    distance(_InputIterator __first, _InputIterator __last)
    {

      return std::__distance(__first, __last,
        std::__iterator_category(__first));
    }

  template<typename _InputIterator, typename _Distance>
    inline constexpr void
    __advance(_InputIterator& __i, _Distance __n, input_iterator_tag)
    {


      do { if (__builtin_is_constant_evaluated() && !bool(__n >= 0)) __builtin_unreachable(); } while (false);
      while (__n--)
 ++__i;
    }

  template<typename _BidirectionalIterator, typename _Distance>
    inline constexpr void
    __advance(_BidirectionalIterator& __i, _Distance __n,
       bidirectional_iterator_tag)
    {



      if (__n > 0)
        while (__n--)
   ++__i;
      else
        while (__n++)
   --__i;
    }

  template<typename _RandomAccessIterator, typename _Distance>
    inline constexpr void
    __advance(_RandomAccessIterator& __i, _Distance __n,
              random_access_iterator_tag)
    {



      if (__builtin_constant_p(__n) && __n == 1)
 ++__i;
      else if (__builtin_constant_p(__n) && __n == -1)
 --__i;
      else
 __i += __n;
    }
# 200 "/usr/bin/../lib/gcc/x86_64-linux-gnu/11/../../../../include/c++/11/bits/stl_iterator_base_funcs.h" 3
  template<typename _InputIterator, typename _Distance>
    inline void
    advance(_InputIterator& __i, _Distance __n)
    {

      typename iterator_traits<_InputIterator>::difference_type __d = __n;
      std::__advance(__i, __d, std::__iterator_category(__i));
    }



  template<typename _InputIterator>
    inline _InputIterator
    next(_InputIterator __x, typename
  iterator_traits<_InputIterator>::difference_type __n = 1)
    {


      std::advance(__x, __n);
      return __x;
    }

  template<typename _BidirectionalIterator>
    inline _BidirectionalIterator
    prev(_BidirectionalIterator __x, typename
  iterator_traits<_BidirectionalIterator>::difference_type __n = 1)
    {



      std::advance(__x, -__n);
      return __x;
    }




}
# 60 "raw_src/stl_vector.h" 2
# 1 "/usr/bin/../lib/gcc/x86_64-linux-gnu/11/../../../../include/c++/11/bits/functexcept.h" 1 3
# 40 "/usr/bin/../lib/gcc/x86_64-linux-gnu/11/../../../../include/c++/11/bits/functexcept.h" 3
# 1 "/usr/bin/../lib/gcc/x86_64-linux-gnu/11/../../../../include/c++/11/bits/exception_defines.h" 1 3
# 41 "/usr/bin/../lib/gcc/x86_64-linux-gnu/11/../../../../include/c++/11/bits/functexcept.h" 2 3

namespace std __attribute__ ((__visibility__ ("default")))
{



  void
  __throw_bad_exception(void) __attribute__((__noreturn__));


  void
  __throw_bad_alloc(void) __attribute__((__noreturn__));

  void
  __throw_bad_array_new_length(void) __attribute__((__noreturn__));


  void
  __throw_bad_cast(void) __attribute__((__noreturn__));

  void
  __throw_bad_typeid(void) __attribute__((__noreturn__));


  void
  __throw_logic_error(const char*) __attribute__((__noreturn__));

  void
  __throw_domain_error(const char*) __attribute__((__noreturn__));

  void
  __throw_invalid_argument(const char*) __attribute__((__noreturn__));

  void
  __throw_length_error(const char*) __attribute__((__noreturn__));

  void
  __throw_out_of_range(const char*) __attribute__((__noreturn__));

  void
  __throw_out_of_range_fmt(const char*, ...) __attribute__((__noreturn__))
    __attribute__((__format__(__gnu_printf__, 1, 2)));

  void
  __throw_runtime_error(const char*) __attribute__((__noreturn__));

  void
  __throw_range_error(const char*) __attribute__((__noreturn__));

  void
  __throw_overflow_error(const char*) __attribute__((__noreturn__));

  void
  __throw_underflow_error(const char*) __attribute__((__noreturn__));


  void
  __throw_ios_failure(const char*) __attribute__((__noreturn__));

  void
  __throw_ios_failure(const char*, int) __attribute__((__noreturn__));


  void
  __throw_system_error(int) __attribute__((__noreturn__));


  void
  __throw_future_error(int) __attribute__((__noreturn__));


  void
  __throw_bad_function_call() __attribute__((__noreturn__));


}
# 61 "raw_src/stl_vector.h" 2


# 1 "/usr/bin/../lib/gcc/x86_64-linux-gnu/11/../../../../include/c++/11/initializer_list" 1 3
# 34 "/usr/bin/../lib/gcc/x86_64-linux-gnu/11/../../../../include/c++/11/initializer_list" 3





#pragma GCC visibility push(default)



namespace std
{

  template<class _E>
    class initializer_list
    {
    public:
      typedef _E value_type;
      typedef const _E& reference;
      typedef const _E& const_reference;
      typedef size_t size_type;
      typedef const _E* iterator;
      typedef const _E* const_iterator;

    private:
      iterator _M_array;
      size_type _M_len;


      constexpr initializer_list(const_iterator __a, size_type __l)
      : _M_array(__a), _M_len(__l) { }

    public:
      constexpr initializer_list() noexcept
      : _M_array(0), _M_len(0) { }


      constexpr size_type
      size() const noexcept { return _M_len; }


      constexpr const_iterator
      begin() const noexcept { return _M_array; }


      constexpr const_iterator
      end() const noexcept { return begin() + size(); }
    };







  template<class _Tp>
    constexpr const _Tp*
    begin(initializer_list<_Tp> __ils) noexcept
    { return __ils.begin(); }







  template<class _Tp>
    constexpr const _Tp*
    end(initializer_list<_Tp> __ils) noexcept
    { return __ils.end(); }
}

#pragma GCC visibility pop
# 64 "raw_src/stl_vector.h" 2
# 77 "raw_src/stl_vector.h"
namespace std __attribute__ ((__visibility__ ("default")))
{




  template<typename _Tp, typename _Alloc>
    struct _Vector_base
    {
      typedef typename __gnu_cxx::__alloc_traits<_Alloc>::template
 rebind<_Tp>::other _Tp_alloc_type;
      typedef typename __gnu_cxx::__alloc_traits<_Tp_alloc_type>::pointer
        pointer;

      struct _Vector_impl_data
      {
 pointer _M_start;
 pointer _M_finish;
 pointer _M_end_of_storage;

 _Vector_impl_data() noexcept
 : _M_start(), _M_finish(), _M_end_of_storage()
 { }


 _Vector_impl_data(_Vector_impl_data&& __x) noexcept
 : _M_start(__x._M_start), _M_finish(__x._M_finish),
   _M_end_of_storage(__x._M_end_of_storage)
 { __x._M_start = __x._M_finish = __x._M_end_of_storage = pointer(); }


 void
 _M_copy_data(_Vector_impl_data const& __x) noexcept
 {
   _M_start = __x._M_start;
   _M_finish = __x._M_finish;
   _M_end_of_storage = __x._M_end_of_storage;
 }

 void
 _M_swap_data(_Vector_impl_data& __x) noexcept
 {


   _Vector_impl_data __tmp;
   __tmp._M_copy_data(*this);
   _M_copy_data(__x);
   __x._M_copy_data(__tmp);
 }
      };

      struct _Vector_impl
 : public _Tp_alloc_type, public _Vector_impl_data
      {
 _Vector_impl() noexcept(is_nothrow_default_constructible<_Tp_alloc_type>::value)

 : _Tp_alloc_type()
 { }

 _Vector_impl(_Tp_alloc_type const& __a) noexcept
 : _Tp_alloc_type(__a)
 { }




 _Vector_impl(_Vector_impl&& __x) noexcept
 : _Tp_alloc_type(std::move(__x)), _Vector_impl_data(std::move(__x))
 { }

 _Vector_impl(_Tp_alloc_type&& __a) noexcept
 : _Tp_alloc_type(std::move(__a))
 { }

 _Vector_impl(_Tp_alloc_type&& __a, _Vector_impl&& __rv) noexcept
 : _Tp_alloc_type(std::move(__a)), _Vector_impl_data(std::move(__rv))
 { }
# 270 "raw_src/stl_vector.h"
      };

    public:
      typedef _Alloc allocator_type;

      _Tp_alloc_type&
      _M_get_Tp_allocator() noexcept
      { return this->_M_impl; }

      const _Tp_alloc_type&
      _M_get_Tp_allocator() const noexcept
      { return this->_M_impl; }

      allocator_type
      get_allocator() const noexcept
      { return allocator_type(_M_get_Tp_allocator()); }


      _Vector_base() = default;




      _Vector_base(const allocator_type& __a) noexcept
      : _M_impl(__a) { }



      _Vector_base(size_t __n)
      : _M_impl()
      { _M_create_storage(__n); }


      _Vector_base(size_t __n, const allocator_type& __a)
      : _M_impl(__a)
      { _M_create_storage(__n); }


      _Vector_base(_Vector_base&&) = default;



      _Vector_base(_Tp_alloc_type&& __a) noexcept
      : _M_impl(std::move(__a)) { }

      _Vector_base(_Vector_base&& __x, const allocator_type& __a)
      : _M_impl(__a)
      {
 if (__x.get_allocator() == __a)
   this->_M_impl._M_swap_data(__x._M_impl);
 else
   {
     size_t __n = __x._M_impl._M_finish - __x._M_impl._M_start;
     _M_create_storage(__n);
   }
      }


      _Vector_base(const allocator_type& __a, _Vector_base&& __x)
      : _M_impl(_Tp_alloc_type(__a), std::move(__x._M_impl))
      { }


      ~_Vector_base() noexcept
      {
 _M_deallocate(_M_impl._M_start,
        _M_impl._M_end_of_storage - _M_impl._M_start);
      }

    public:
      _Vector_impl _M_impl;

      pointer
      _M_allocate(size_t __n)
      {
 typedef __gnu_cxx::__alloc_traits<_Tp_alloc_type> _Tr;
 return __n != 0 ? _Tr::allocate(_M_impl, __n) : pointer();
      }

      void
      _M_deallocate(pointer __p, size_t __n)
      {
 typedef __gnu_cxx::__alloc_traits<_Tp_alloc_type> _Tr;
 if (__p)
   _Tr::deallocate(_M_impl, __p, __n);
      }

    protected:
      void
      _M_create_storage(size_t __n)
      {
 this->_M_impl._M_start = this->_M_allocate(__n);
 this->_M_impl._M_finish = this->_M_impl._M_start;
 this->_M_impl._M_end_of_storage = this->_M_impl._M_start + __n;
      }
    };
# 388 "raw_src/stl_vector.h"
  template<typename _Tp, typename _Alloc = std::allocator<_Tp> >
    class vector : protected _Vector_base<_Tp, _Alloc>
    {
# 401 "raw_src/stl_vector.h"
      static_assert(is_same<typename remove_cv<_Tp>::type, _Tp>::value,
   "std::vector must have a non-const, non-volatile value_type");






      typedef _Vector_base<_Tp, _Alloc> _Base;
      typedef typename _Base::_Tp_alloc_type _Tp_alloc_type;
      typedef __gnu_cxx::__alloc_traits<_Tp_alloc_type> _Alloc_traits;

    public:
      typedef _Tp value_type;
      typedef typename _Base::pointer pointer;
      typedef typename _Alloc_traits::const_pointer const_pointer;
      typedef typename _Alloc_traits::reference reference;
      typedef typename _Alloc_traits::const_reference const_reference;
      typedef __gnu_cxx::__normal_iterator<pointer, vector> iterator;
      typedef __gnu_cxx::__normal_iterator<const_pointer, vector>
      const_iterator;
      typedef std::reverse_iterator<const_iterator> const_reverse_iterator;
      typedef std::reverse_iterator<iterator> reverse_iterator;
      typedef size_t size_type;
      typedef ptrdiff_t difference_type;
      typedef _Alloc allocator_type;

    private:

      static constexpr bool
      _S_nothrow_relocate(true_type)
      {
 return noexcept(std::__relocate_a(std::declval<pointer>(),
       std::declval<pointer>(),
       std::declval<pointer>(),
       std::declval<_Tp_alloc_type&>()));
      }

      static constexpr bool
      _S_nothrow_relocate(false_type)
      { return false; }

      static constexpr bool
      _S_use_relocate()
      {



 return _S_nothrow_relocate(__is_move_insertable<_Tp_alloc_type>{});
      }

      static pointer
      _S_do_relocate(pointer __first, pointer __last, pointer __result,
       _Tp_alloc_type& __alloc, true_type) noexcept
      {
 return std::__relocate_a(__first, __last, __result, __alloc);
      }

      static pointer
      _S_do_relocate(pointer, pointer, pointer __result,
       _Tp_alloc_type&, false_type) noexcept
      { return __result; }

      static pointer
      _S_relocate(pointer __first, pointer __last, pointer __result,
    _Tp_alloc_type& __alloc) noexcept
      {
 using __do_it = __bool_constant<_S_use_relocate()>;
 return _S_do_relocate(__first, __last, __result, __alloc, __do_it{});
      }


    protected:
      using _Base::_M_allocate;
      using _Base::_M_deallocate;
      using _Base::_M_impl;
      using _Base::_M_get_Tp_allocator;

    public:







      vector() = default;
# 496 "raw_src/stl_vector.h"
      explicit
      vector(const allocator_type& __a) noexcept
      : _Base(__a) { }
# 509 "raw_src/stl_vector.h"
      explicit
      vector(size_type __n, const allocator_type& __a = allocator_type())
      : _Base(_S_check_init_len(__n, __a), __a)
      { _M_default_initialize(__n); }
# 522 "raw_src/stl_vector.h"
      vector(size_type __n, const value_type& __value,
      const allocator_type& __a = allocator_type())
      : _Base(_S_check_init_len(__n, __a), __a)
      { _M_fill_initialize(__n, __value); }
# 553 "raw_src/stl_vector.h"
      vector(const vector& __x)
      : _Base(__x.size(),
 _Alloc_traits::_S_select_on_copy(__x._M_get_Tp_allocator()))
      {
 this->_M_impl._M_finish =
   std::__uninitialized_copy_a(__x.begin(), __x.end(),
          this->_M_impl._M_start,
          _M_get_Tp_allocator());
      }
# 572 "raw_src/stl_vector.h"
      vector(vector&&) noexcept = default;


      vector(const vector& __x, const allocator_type& __a)
      : _Base(__x.size(), __a)
      {
 this->_M_impl._M_finish =
   std::__uninitialized_copy_a(__x.begin(), __x.end(),
          this->_M_impl._M_start,
          _M_get_Tp_allocator());
      }

    private:
      vector(vector&& __rv, const allocator_type& __m, true_type) noexcept
      : _Base(__m, std::move(__rv))
      { }

      vector(vector&& __rv, const allocator_type& __m, false_type)
      : _Base(__m)
      {
 if (__rv.get_allocator() == __m)
   this->_M_impl._M_swap_data(__rv._M_impl);
 else if (!__rv.empty())
   {
     this->_M_create_storage(__rv.size());
     this->_M_impl._M_finish =
       std::__uninitialized_move_a(__rv.begin(), __rv.end(),
       this->_M_impl._M_start,
       _M_get_Tp_allocator());
     __rv.clear();
   }
      }

    public:

      vector(vector&& __rv, const allocator_type& __m)
      noexcept( noexcept(
 vector(std::declval<vector&&>(), std::declval<const allocator_type&>(),
        std::declval<typename _Alloc_traits::is_always_equal>())) )
      : vector(std::move(__rv), __m, typename _Alloc_traits::is_always_equal{})
      { }
# 625 "raw_src/stl_vector.h"
      vector(initializer_list<value_type> __l,
      const allocator_type& __a = allocator_type())
      : _Base(__a)
      {
 _M_range_initialize(__l.begin(), __l.end(),
       random_access_iterator_tag());
      }
# 651 "raw_src/stl_vector.h"
      template<typename _InputIterator,
        typename = std::_RequireInputIter<_InputIterator>>
 vector(_InputIterator __first, _InputIterator __last,
        const allocator_type& __a = allocator_type())
 : _Base(__a)
 {
   _M_range_initialize(__first, __last,
         std::__iterator_category(__first));
 }
# 678 "raw_src/stl_vector.h"
      ~vector() noexcept
      {
 std::_Destroy(this->_M_impl._M_start, this->_M_impl._M_finish,
        _M_get_Tp_allocator());
                                      ;
      }
# 694 "raw_src/stl_vector.h"
      vector&
      operator=(const vector& __x);
# 708 "raw_src/stl_vector.h"
      vector&
      operator=(vector&& __x) noexcept(_Alloc_traits::_S_nothrow_move())
      {
 constexpr bool __move_storage =
   _Alloc_traits::_S_propagate_on_move_assign()
   || _Alloc_traits::_S_always_equal();
 _M_move_assign(std::move(__x), __bool_constant<__move_storage>());
 return *this;
      }
# 729 "raw_src/stl_vector.h"
      vector&
      operator=(initializer_list<value_type> __l)
      {
 this->_M_assign_aux(__l.begin(), __l.end(),
       random_access_iterator_tag());
 return *this;
      }
# 748 "raw_src/stl_vector.h"
      void
      assign(size_type __n, const value_type& __val)
      { _M_fill_assign(__n, __val); }
# 765 "raw_src/stl_vector.h"
      template<typename _InputIterator,
        typename = std::_RequireInputIter<_InputIterator>>
 void
 assign(_InputIterator __first, _InputIterator __last)
 { _M_assign_dispatch(__first, __last, __false_type()); }
# 793 "raw_src/stl_vector.h"
      void
      assign(initializer_list<value_type> __l)
      {
 this->_M_assign_aux(__l.begin(), __l.end(),
       random_access_iterator_tag());
      }



      using _Base::get_allocator;







      iterator
      begin() noexcept
      { return iterator(this->_M_impl._M_start); }






      const_iterator
      begin() const noexcept
      { return const_iterator(this->_M_impl._M_start); }






      iterator
      end() noexcept
      { return iterator(this->_M_impl._M_finish); }






      const_iterator
      end() const noexcept
      { return const_iterator(this->_M_impl._M_finish); }






      reverse_iterator
      rbegin() noexcept
      { return reverse_iterator(end()); }






      const_reverse_iterator
      rbegin() const noexcept
      { return const_reverse_iterator(end()); }






      reverse_iterator
      rend() noexcept
      { return reverse_iterator(begin()); }






      const_reverse_iterator
      rend() const noexcept
      { return const_reverse_iterator(begin()); }







      const_iterator
      cbegin() const noexcept
      { return const_iterator(this->_M_impl._M_start); }






      const_iterator
      cend() const noexcept
      { return const_iterator(this->_M_impl._M_finish); }






      const_reverse_iterator
      crbegin() const noexcept
      { return const_reverse_iterator(end()); }






      const_reverse_iterator
      crend() const noexcept
      { return const_reverse_iterator(begin()); }




      size_type
      size() const noexcept
      { return size_type(this->_M_impl._M_finish - this->_M_impl._M_start); }


      size_type
      max_size() const noexcept
      { return _S_max_size(_M_get_Tp_allocator()); }
# 936 "raw_src/stl_vector.h"
      void
      resize(size_type __new_size)
      {
 if (__new_size > size())
   _M_default_append(__new_size - size());
 else if (__new_size < size())
   _M_erase_at_end(this->_M_impl._M_start + __new_size);
      }
# 956 "raw_src/stl_vector.h"
      void
      resize(size_type __new_size, const value_type& __x)
      {
 if (__new_size > size())
   _M_fill_insert(end(), __new_size - size(), __x);
 else if (__new_size < size())
   _M_erase_at_end(this->_M_impl._M_start + __new_size);
      }
# 988 "raw_src/stl_vector.h"
      void
      shrink_to_fit()
      { _M_shrink_to_fit(); }






      size_type
      capacity() const noexcept
      { return size_type(this->_M_impl._M_end_of_storage
    - this->_M_impl._M_start); }





                         bool
      empty() const noexcept
      { return begin() == end(); }
# 1027 "raw_src/stl_vector.h"
      void
      reserve(size_type __n);
# 1042 "raw_src/stl_vector.h"
      reference
      operator[](size_type __n) noexcept
      {
                                  ;
 return *(this->_M_impl._M_start + __n);
      }
# 1060 "raw_src/stl_vector.h"
      const_reference
      operator[](size_type __n) const noexcept
      {
                                  ;
 return *(this->_M_impl._M_start + __n);
      }

    protected:

      void
      _M_range_check(size_type __n) const
      {
 if (__n >= this->size())
   __throw_out_of_range_fmt(("vector::_M_range_check: __n " "(which is %zu) >= this->size() " "(which is %zu)"),


       __n, this->size());
      }

    public:
# 1091 "raw_src/stl_vector.h"
      reference
      at(size_type __n)
      {
 _M_range_check(__n);
 return (*this)[__n];
      }
# 1109 "raw_src/stl_vector.h"
      const_reference
      at(size_type __n) const
      {
 _M_range_check(__n);
 return (*this)[__n];
      }





      reference
      front() noexcept
      {
                              ;
 return *begin();
      }





      const_reference
      front() const noexcept
      {
                              ;
 return *begin();
      }





      reference
      back() noexcept
      {
                              ;
 return *(end() - 1);
      }





      const_reference
      back() const noexcept
      {
                              ;
 return *(end() - 1);
      }
# 1167 "raw_src/stl_vector.h"
      _Tp*
      data() noexcept
      { return _M_data_ptr(this->_M_impl._M_start); }

      const _Tp*
      data() const noexcept
      { return _M_data_ptr(this->_M_impl._M_start); }
# 1186 "raw_src/stl_vector.h"
      void
      push_back(const value_type& __x)
      {
 if (this->_M_impl._M_finish != this->_M_impl._M_end_of_storage)
   {
                                   ;
     _Alloc_traits::construct(this->_M_impl, this->_M_impl._M_finish,
         __x);
     ++this->_M_impl._M_finish;
                                   ;
   }
 else
   _M_realloc_insert(end(), __x);
      }


      void
      push_back(value_type&& __x)
      { emplace_back(std::move(__x)); }

      template<typename... _Args>



 void

 emplace_back(_Args&&... __args);
# 1224 "raw_src/stl_vector.h"
      void
      pop_back() noexcept
      {
                              ;
 --this->_M_impl._M_finish;
 _Alloc_traits::destroy(this->_M_impl, this->_M_impl._M_finish);
                                 ;
      }
# 1246 "raw_src/stl_vector.h"
      template<typename... _Args>
 iterator
 emplace(const_iterator __position, _Args&&... __args)
 { return _M_emplace_aux(__position, std::forward<_Args>(__args)...); }
# 1262 "raw_src/stl_vector.h"
      iterator
      insert(const_iterator __position, const value_type& __x);
# 1292 "raw_src/stl_vector.h"
      iterator
      insert(const_iterator __position, value_type&& __x)
      { return _M_insert_rval(__position, std::move(__x)); }
# 1309 "raw_src/stl_vector.h"
      iterator
      insert(const_iterator __position, initializer_list<value_type> __l)
      {
 auto __offset = __position - cbegin();
 _M_range_insert(begin() + __offset, __l.begin(), __l.end(),
   std::random_access_iterator_tag());
 return begin() + __offset;
      }
# 1334 "raw_src/stl_vector.h"
      iterator
      insert(const_iterator __position, size_type __n, const value_type& __x)
      {
 difference_type __offset = __position - cbegin();
 _M_fill_insert(begin() + __offset, __n, __x);
 return begin() + __offset;
      }
# 1376 "raw_src/stl_vector.h"
      template<typename _InputIterator,
        typename = std::_RequireInputIter<_InputIterator>>
 iterator
 insert(const_iterator __position, _InputIterator __first,
        _InputIterator __last)
 {
   difference_type __offset = __position - cbegin();
   _M_insert_dispatch(begin() + __offset,
        __first, __last, __false_type());
   return begin() + __offset;
 }
# 1428 "raw_src/stl_vector.h"
      iterator

      erase(const_iterator __position)
      { return _M_erase(begin() + (__position - cbegin())); }
# 1455 "raw_src/stl_vector.h"
      iterator

      erase(const_iterator __first, const_iterator __last)
      {
 const auto __beg = begin();
 const auto __cbeg = cbegin();
 return _M_erase(__beg + (__first - __cbeg), __beg + (__last - __cbeg));
      }
# 1479 "raw_src/stl_vector.h"
      void
      swap(vector& __x) noexcept
      {

 do { if (__builtin_is_constant_evaluated() && !bool(_Alloc_traits::propagate_on_container_swap::value || _M_get_Tp_allocator() == __x._M_get_Tp_allocator())) __builtin_unreachable(); } while (false);


 this->_M_impl._M_swap_data(__x._M_impl);
 _Alloc_traits::_S_on_swap(_M_get_Tp_allocator(),
      __x._M_get_Tp_allocator());
      }







      void
      clear() noexcept
      { _M_erase_at_end(this->_M_impl._M_start); }

    protected:




      template<typename _ForwardIterator>
 pointer
 _M_allocate_and_copy(size_type __n,
        _ForwardIterator __first, _ForwardIterator __last)
 {
   pointer __result = this->_M_allocate(__n);
   try
     {
       std::__uninitialized_copy_a(__first, __last, __result,
       _M_get_Tp_allocator());
       return __result;
     }
   catch(...)
     {
       _M_deallocate(__result, __n);
       throw;
     }
 }
# 1556 "raw_src/stl_vector.h"
      template<typename _InputIterator>
 void
 _M_range_initialize(_InputIterator __first, _InputIterator __last,
       std::input_iterator_tag)
 {
   try {
     for (; __first != __last; ++__first)

       emplace_back(*__first);



   } catch(...) {
     clear();
     throw;
   }
 }


      template<typename _ForwardIterator>
 void
 _M_range_initialize(_ForwardIterator __first, _ForwardIterator __last,
       std::forward_iterator_tag)
 {
   const size_type __n = std::distance(__first, __last);
   this->_M_impl._M_start
     = this->_M_allocate(_S_check_init_len(__n, _M_get_Tp_allocator()));
   this->_M_impl._M_end_of_storage = this->_M_impl._M_start + __n;
   this->_M_impl._M_finish =
     std::__uninitialized_copy_a(__first, __last,
     this->_M_impl._M_start,
     _M_get_Tp_allocator());
 }



      void
      _M_fill_initialize(size_type __n, const value_type& __value)
      {
 this->_M_impl._M_finish =
   std::__uninitialized_fill_n_a(this->_M_impl._M_start, __n, __value,
     _M_get_Tp_allocator());
      }



      void
      _M_default_initialize(size_type __n)
      {
 this->_M_impl._M_finish =
   std::__uninitialized_default_n_a(this->_M_impl._M_start, __n,
        _M_get_Tp_allocator());
      }
# 1618 "raw_src/stl_vector.h"
      template<typename _Integer>
 void
 _M_assign_dispatch(_Integer __n, _Integer __val, __true_type)
 { _M_fill_assign(__n, __val); }


      template<typename _InputIterator>
 void
 _M_assign_dispatch(_InputIterator __first, _InputIterator __last,
      __false_type)
 { _M_assign_aux(__first, __last, std::__iterator_category(__first)); }


      template<typename _InputIterator>
 void
 _M_assign_aux(_InputIterator __first, _InputIterator __last,
        std::input_iterator_tag);


      template<typename _ForwardIterator>
 void
 _M_assign_aux(_ForwardIterator __first, _ForwardIterator __last,
        std::forward_iterator_tag);



      void
      _M_fill_assign(size_type __n, const value_type& __val);







      template<typename _Integer>
 void
 _M_insert_dispatch(iterator __pos, _Integer __n, _Integer __val,
      __true_type)
 { _M_fill_insert(__pos, __n, __val); }


      template<typename _InputIterator>
 void
 _M_insert_dispatch(iterator __pos, _InputIterator __first,
      _InputIterator __last, __false_type)
 {
   _M_range_insert(__pos, __first, __last,
     std::__iterator_category(__first));
 }


      template<typename _InputIterator>
 void
 _M_range_insert(iterator __pos, _InputIterator __first,
   _InputIterator __last, std::input_iterator_tag);


      template<typename _ForwardIterator>
 void
 _M_range_insert(iterator __pos, _ForwardIterator __first,
   _ForwardIterator __last, std::forward_iterator_tag);



      void
      _M_fill_insert(iterator __pos, size_type __n, const value_type& __x);



      void
      _M_default_append(size_type __n);

      bool
      _M_shrink_to_fit();
# 1705 "raw_src/stl_vector.h"
      struct _Temporary_value
      {
 template<typename... _Args>
   explicit
   _Temporary_value(vector* __vec, _Args&&... __args) : _M_this(__vec)
   {
     _Alloc_traits::construct(_M_this->_M_impl, _M_ptr(),
         std::forward<_Args>(__args)...);
   }

 ~_Temporary_value()
 { _Alloc_traits::destroy(_M_this->_M_impl, _M_ptr()); }

 value_type&
 _M_val() { return *_M_ptr(); }

      private:
 _Tp*
 _M_ptr() { return reinterpret_cast<_Tp*>(&__buf); }

 vector* _M_this;
 typename aligned_storage<sizeof(_Tp), alignof(_Tp)>::type __buf;
      };



      template<typename _Arg>
 void
 _M_insert_aux(iterator __position, _Arg&& __arg);

      template<typename... _Args>
 void
 _M_realloc_insert(iterator __position, _Args&&... __args);


      iterator
      _M_insert_rval(const_iterator __position, value_type&& __v);


      template<typename... _Args>
 iterator
 _M_emplace_aux(const_iterator __position, _Args&&... __args);


      iterator
      _M_emplace_aux(const_iterator __position, value_type&& __v)
      { return _M_insert_rval(__position, std::move(__v)); }



      size_type
      _M_check_len(size_type __n, const char* __s) const
      {
 if (max_size() - size() < __n)
   __throw_length_error((__s));

 const size_type __len = size() + (std::max)(size(), __n);
 return (__len < size() || __len > max_size()) ? max_size() : __len;
      }


      static size_type
      _S_check_init_len(size_type __n, const allocator_type& __a)
      {
 if (__n > _S_max_size(_Tp_alloc_type(__a)))
   __throw_length_error(
       ("cannot create std::vector larger than max_size()"));
 return __n;
      }

      static size_type
      _S_max_size(const _Tp_alloc_type& __a) noexcept
      {



 const size_t __diffmax
   = __gnu_cxx::__numeric_traits<ptrdiff_t>::__max / sizeof(_Tp);
 const size_t __allocmax = _Alloc_traits::max_size(__a);
 return (std::min)(__diffmax, __allocmax);
      }





      void
      _M_erase_at_end(pointer __pos) noexcept
      {
 if (size_type __n = this->_M_impl._M_finish - __pos)
   {
     std::_Destroy(__pos, this->_M_impl._M_finish,
     _M_get_Tp_allocator());
     this->_M_impl._M_finish = __pos;
                                       ;
   }
      }

      iterator
      _M_erase(iterator __position);

      iterator
      _M_erase(iterator __first, iterator __last);


    private:



      void
      _M_move_assign(vector&& __x, true_type) noexcept
      {
 vector __tmp(get_allocator());
 this->_M_impl._M_swap_data(__x._M_impl);
 __tmp._M_impl._M_swap_data(__x._M_impl);
 std::__alloc_on_move(_M_get_Tp_allocator(), __x._M_get_Tp_allocator());
      }



      void
      _M_move_assign(vector&& __x, false_type)
      {
 if (__x._M_get_Tp_allocator() == this->_M_get_Tp_allocator())
   _M_move_assign(std::move(__x), true_type());
 else
   {


     this->_M_assign_aux(std::make_move_iterator(__x.begin()),
           std::make_move_iterator(__x.end()),
    std::random_access_iterator_tag());
     __x.clear();
   }
      }


      template<typename _Up>
 _Up*
 _M_data_ptr(_Up* __ptr) const noexcept
 { return __ptr; }


      template<typename _Ptr>
 typename std::pointer_traits<_Ptr>::element_type*
 _M_data_ptr(_Ptr __ptr) const
 { return empty() ? nullptr : std::__to_address(__ptr); }
# 1868 "raw_src/stl_vector.h"
    };
# 1890 "raw_src/stl_vector.h"
  template<typename _Tp, typename _Alloc>
    inline bool
    operator==(const vector<_Tp, _Alloc>& __x, const vector<_Tp, _Alloc>& __y)
    { return (__x.size() == __y.size()
       && std::equal(__x.begin(), __x.end(), __y.begin())); }
# 1928 "raw_src/stl_vector.h"
  template<typename _Tp, typename _Alloc>
    inline bool
    operator<(const vector<_Tp, _Alloc>& __x, const vector<_Tp, _Alloc>& __y)
    { return std::lexicographical_compare(__x.begin(), __x.end(),
       __y.begin(), __y.end()); }


  template<typename _Tp, typename _Alloc>
    inline bool
    operator!=(const vector<_Tp, _Alloc>& __x, const vector<_Tp, _Alloc>& __y)
    { return !(__x == __y); }


  template<typename _Tp, typename _Alloc>
    inline bool
    operator>(const vector<_Tp, _Alloc>& __x, const vector<_Tp, _Alloc>& __y)
    { return __y < __x; }


  template<typename _Tp, typename _Alloc>
    inline bool
    operator<=(const vector<_Tp, _Alloc>& __x, const vector<_Tp, _Alloc>& __y)
    { return !(__y < __x); }


  template<typename _Tp, typename _Alloc>
    inline bool
    operator>=(const vector<_Tp, _Alloc>& __x, const vector<_Tp, _Alloc>& __y)
    { return !(__x < __y); }



  template<typename _Tp, typename _Alloc>
    inline void
    swap(vector<_Tp, _Alloc>& __x, vector<_Tp, _Alloc>& __y)
    noexcept(noexcept(__x.swap(__y)))
    { __x.swap(__y); }
# 1983 "raw_src/stl_vector.h"
}
