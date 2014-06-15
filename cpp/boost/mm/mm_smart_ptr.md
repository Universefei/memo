smart_ptr
=========

- std::auto_ptr (C++98 standard)
- boost::scoped_ptr
- boost::scoped_array
- boost::shared_ptr
- boost::shared_array
- boost::weak_ptr
- boost::intrusive_ptr

## std::auto_ptr

## boost::scoped_ptr

```c++

template<class T>
class scoped_ptr {             //noncopyable
	private:
		T * px;
		scoped_ptr(scoped_ptr const &);
		scoped_ptr & operator=(scoped_ptr const &);
	public:
		explicit scoped_ptr(T * p = 0);
		~scoped_ptr();

		void reset(T * p = 0);

		T & operator*() const;
		T * operator->() const;
		T * get() const;

		operator unspecified-bool-type() const;
		void swap(scoped_ptr & b);
};

```

## boost::scoped_array

```c++

template<class T> 
class scoped_array {  //noncopyable
	public:
		explicit scoped_array(T * p = 0);
		~scoped_array();

		void reset(T * p = 0);
		T & operator[](std::ptrdiff_t i) const;
		T * get() const;

		operator unspecified-bool-type() const;
		void swap(scoped_array &b);
};

```

## boost::shared_ptr

```c++

template<class T> 
class shared_ptr {
	public:
		typedef T element_type;

		shared_ptr();
		template<class Y> explicit shared_ptr(Y * p);
		template<class Y, class D> shared_prt(Y * p, D d);
		~shared_ptr();

		shared_ptr(shared_ptr const & r);
		template<class Y> explicit shared_ptr(std::auto_ptr<Y> & r);

		shared_ptr & operator=(shared_ptr const & r);
		template<class Y> shared_ptr & operator=(shared_ptr<Y> const & r);
		template<class Y> shared_ptr & operator=(std::auto_ptr<Y> & r);

		void reset();
		template<class Y> void reset(Y * p);
		template<class Y, class D> void reset(Y * p, D d);

		T & operator*() const;
		T * operator->() const;
		T * get() const;

		bool unique() const;
		long use_count() const;

		operator unspecified-bool-type() const;
		void swap(shared_ptr & b);
};

```

## boost::shared_array

```c++
template<class T>
class shared_array {
	public:
		explicit shared_array(T * p = 0);
		template<class D> shared_array(T * p, D d);
		~shared_array();

		shared_array(shared_array const & r);

		shared_array & operator=(shared_array const & r);

		void reset(T * p = 0);
		template<class D> void reset(T * p, D d);

		T & operator[]:(std::ptrdiff_t i) const() const;
		T * get() const;

		bool unique() const;
		long use_count() const;

		void swap(shared_array<T> & b);
};
```

## boost::weak_ptr

```c++
template<class T>
class weak_ptr {
	public:
		weak_ptr();

		template<class Y> weak_ptr(shared_ptr<Y> const & r);
		weak_ptr(weak_ptr const & r);

		~weak_ptr();
		
		weak_ptr & operator=(weak_ptr const & r);

		long use_count() const;
		bool expired() const;
		shared_ptr<T> lock() const;

		void reset();
		void swap(weak_ptr<T> & b);
};
```

## boost::intrusive_ptr




