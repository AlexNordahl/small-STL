#ifndef small_stl_vector
#define small_stl_vector

namespace sSTL
{
    template<typename T>
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

        ~vector() { delete[] m_array; };

    private:
        size_t m_size {};
        size_t m_capacity {};
        T* m_array {};
        static constexpr size_t max_size {2'000'000};
    };

    template<typename T>
    vector<T>::vector(size_t size)
        : m_size {size}, m_capacity {size}
    {
        m_array = new T[m_size];
    }

    template<typename T>
    vector<T>::vector(size_t size, T init)
        : vector(size)
    {
        for (size_t i = 0; i < m_size; ++i)
            m_array[i] = init;
    }
}

#endif