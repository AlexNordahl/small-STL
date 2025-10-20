#ifndef small_stl_vector
#define small_stl_vector

#include <memory>
#include <initializer_list>

namespace sSTL
{
    template<typename T, typename Allocator = std::allocator<T>>
    class vector
    {
    public:
        vector() = default;
        vector(size_t size);
        vector(std::initializer_list<T> list);
        
        T& at(size_t index) { return m_memory[index]; };
        T& operator[] (size_t index) { return at(index); };

        size_t size() const { return m_size; };
        size_t capacity() const { return m_capacity; };

        void push_back(T element);

        ~vector() { allocator.deallocate(m_memory, m_size); };

    private:
        size_t m_size {};
        size_t m_capacity {};
        T* m_memory {};
        static constexpr size_t max_size {1'000'000};
    };

    template<typename T, typename Allocator>
    void vector<T, Allocator>::push_back(T element)
    {
        Allocator allocator;
    }
    
    template<typename T, typename Allocator>
    vector<T, Allocator>::vector(size_t size)
    : m_size {size}, m_capacity {size}
    {
        Allocator allocator;
        m_memory = allocator.allocate(m_capacity);
        for (size_t i = 0; i < m_size; ++i)
        {
            allocator.construct(&m_memory[i], T{});
        }
    }
    
    template<typename T, typename Allocator>
    vector<T, Allocator>::vector(std::initializer_list<T> list)
        : vector(list.size())
    {}
}

#endif