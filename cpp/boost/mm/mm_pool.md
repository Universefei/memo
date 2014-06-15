Pool
====

memory pool 预先分配了一大块的内存空间，然后就可以在其中使用某种算法实现高效
快速的自定制内存分配。

boost.pool库基于简单分隔存储思想实现了一个快速/紧凑的内存池库，不仅能够管理
大量的对象，还可以被用作STL的内存分配器。某种程度上来说，它近似于一个小型的
垃圾回收机制，在需要大量地分配/释放小对象时很有效率，而且完全不需要考虑delete.

Pool 库包括四个组成部分：
- 最简单的 pool
- 分配类实例的 object_pool
- 单件内存池 singleton_pool
- 可用于标准库的 pool_alloc

## pool

```c++
template <typename UserAllocator = ... >
class pool {
	public:
		explicit pool(size_type requested_size);
		~pool();
		size_type get_requested_size() const;

		void * malloc();
		void * ordered_malloc();
		void * ordered_malloc(size_type n);
		bool is_from(void * chunk) const;

		void free(void * chunk);
		void ordered_free(void * chunk);
		void free(void * chunks, size_type n);
		void ordered_free(void * chunks, size_type n);

		bool release_memory();
		bool purge_memory();
};
```

## object_pool

```c++
template <typename ElementType>
class object_pool: protected pool {
	public:
		object_pool();
		~object_pool();

		element_type * malloc();
		void free(element_type * p);
		bool is_free(element_type * p) const;

		element_type * construct(...);
		void destroy(element_type * p);
};
```

## singleton_pool

```c++
template <typename Tag, nusigned RequestedSize>
class Singleton_pool {
	public:
		static bool is_from(void * ptr);
		static void * malloc();
		static void * ordered_malloc();
		static void * ordered_malloc(size_type n);

		static void free(void * ptr);
		static void ordered_free(void * ptr);
		static void free(void *ptr, std::size_t n);
		static void ordered_free(void * ptr, size_type n);

		static bool release_memory();
		static boolpurge_memory();
};
```

## pool_alloc



