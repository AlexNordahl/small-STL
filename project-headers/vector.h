#ifndef small_stl_vector
#define small_stl_vector

#include <memory>

namespace sSTL
{
    template<typename T, typename Allocator = std::allocator<T>>
    class vector
    {
    public:
        vector() = default;
        vector(size_t size);
        vector(size_t size, T init);
        
        T& at(size_t index) { return m_array[index]; };
        T& operator[] (size_t index) { return at(index); };

        size_t size() const { return m_size; };
        size_t capacity() const { return m_capacity; };

        ~vector() { allocator.deallocate(m_array, m_size); };

    private:
        size_t m_size {};
        size_t m_capacity {};
        T* m_array {};
        Allocator allocator;
        static constexpr size_t max_size {2'000'000};
    };

    template<typename T, typename Allocator>
    vector<T, Allocator>::vector(size_t size)
        : m_size {size}, m_capacity {size}
    {
        m_array = allocator.allocate(m_size);
    }

    template<typename T, typename Allocator>
    vector<T, Allocator>::vector(size_t size, T init)
        : vector(size)
    {
        for (size_t i = 0; i < m_size; ++i)
            m_array[i] = init;
    }
}

#endif