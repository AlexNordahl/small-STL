#ifndef SMALL_STL_ARRAY
#define SMALL_STL_ARRAY

#include <cstddef>
#include <initializer_list>

namespace sSTL
{
    template<typename T, std::size_t N>
    struct array
    {
        T m_array[N];

        T& at(std::size_t index)
        {
            if (index >= N)
                throw std::out_of_range("Position out of bounds.\n");

            return m_array[index];
        }

        T& operator[] (std::size_t index)
        {
            return m_array[index];
        }

        T& front()
        {
            return m_array[0];
        }

        T& back()
        {
            return m_array[N - 1];
        }

        T* data()
        {
            return m_array;
        }

        constexpr bool empty() const { return N == 0; }
        constexpr std::size_t size() const { return N; }

        void fill(T value)
        {
            for (size_t i {}; i < N; ++i)
                m_array[i] = value;
        }
    };
}

#endif