#ifndef SMALL_STL_VECTOR
#define SMALL_STL_VECTOR

#include "iterator.h"
#include <memory>
#include <initializer_list>
#include <utility>
#include <stdexcept>
#include <cstddef>

namespace sSTL
{
    template<typename T, typename Allocator = std::allocator<T>>
    class vector final
    {
    public:
        using iterator = T*;
        using const_iterator = const T*;
        using reverse_iterator = std::reverse_iterator<iterator>;
        using const_reverse_iterator = const sSTL::reverse_iterator<iterator>;

        vector() = default;

        vector(std::size_t size)
            : m_size {size}, m_capacity {size}
        {
            Allocator allocator;
            m_memory = allocator.allocate(m_capacity);
            for (std::size_t i {}; i < m_size; ++i)
                allocator.construct(&m_memory[i], T{});
        }

        vector(std::initializer_list<T> list)
            : m_size {list.size()}, m_capacity {list.size()}
        {
            Allocator allocator;
            m_memory = allocator.allocate(m_capacity);

            std::size_t i {};
            for (const auto& item : list)
                allocator.construct(&m_memory[i++], item);
        }
        
        vector(const vector& other)
        {
            copy_from(other);
        }
        
        vector(vector&& other)
        {
            move_from(other);
        }

        vector& operator=(const vector& other)
        {
            if (this == &other) 
                return *this;

            copy_from(other);
            return *this;
        }

        vector& operator=(vector&& other)
        {
            free_currrent_memory();
            move_from(other);

            return *this;
        }

        T& at(std::size_t index)
        { 
            if (index >= m_size)
            {
                throw std::out_of_range("Given index is too big\n");
            }
            return m_memory[index]; 
        };

        T& operator[] (std::size_t index) { return m_memory[index]; };

        std::size_t size() const { return m_size; };
        std::size_t capacity() const { return m_capacity; };

        void push_back(const T& element)
        {
            if (m_size == max_size())
                return;

            Allocator allocator;
            if (m_size < m_capacity)
            {
                allocator.construct(&m_memory[m_size++], element);
                return;
            }

            std::size_t new_capacity {m_capacity == 0 ? 1 : m_size * growth_rate()};
            reserve(new_capacity);
            
            allocator.construct(&m_memory[m_size++], element);
        }

        void pop_back()
        {
            Allocator allocator;
            allocator.destroy(&m_memory[--m_size]);
        }

        void shrink_to_fit() { reserve(m_size); }

        void reserve(std::size_t capacity)
        {
            if (capacity < m_size)
                return;

            Allocator allocator;
            T* new_memory = allocator.allocate(capacity);

            for (std::size_t i {}; i < m_size; ++i)
                allocator.construct(&new_memory[i], m_memory[i]);

            free_currrent_memory();
            
            m_memory = new_memory;
            m_capacity = capacity;
        }

        void clear()
        {
            if (!m_size)
                return;

            Allocator allocator;
            for (std::size_t i {}; i < m_size; ++i)
                allocator.destroy(&m_memory[i]);
            m_size = 0;
        }

        iterator begin() { return m_memory; };
        iterator end() { return (m_memory + m_size); }
        reverse_iterator rbegin() { return {end() - 1}; };
        reverse_iterator rend() { return {begin() - 1}; }

        const_iterator cbegin() const { return m_memory; }
        const_iterator cend() const { return (m_memory + m_size); }
        const_reverse_iterator crbegin() const { return {end() - 1}; }
        const_reverse_iterator crend() const { return {begin() - 1}; }

        ~vector() 
        { 
            Allocator allocator;
            for (std::size_t i {}; i < m_size; ++i)
                allocator.destroy(&m_memory[i]);
            
            if (m_memory)
                allocator.deallocate(m_memory, m_capacity); 
        };

    private:
        std::size_t m_size {};
        std::size_t m_capacity {};
        T* m_memory {};

        void copy_from(const vector& other)
        {
            Allocator allocator;
            T* new_memory = allocator.allocate(other.m_capacity);

            for (std::size_t i {}; i < other.m_size; ++i)
                allocator.construct(&new_memory[i], other.m_memory[i]);

            free_currrent_memory();

            m_memory = new_memory;
            m_capacity = other.m_capacity;
            m_size = other.m_size;
        }

        void move_from(vector& other)
        {
            m_memory = other.m_memory;
            m_size = other.m_size;
            m_capacity = other.m_capacity;

            other.m_memory = nullptr;
            other.m_size = 0;
            other.m_capacity = 0;
        }

        void free_currrent_memory()
        {
            if (m_memory)
            {
                Allocator allocator;
                for (std::size_t i {}; i < m_size; ++i)
                    allocator.destroy(&m_memory[i]);
                allocator.deallocate(m_memory, m_capacity);
            }
        }

        std::size_t max_size() const { return 1'000'000; }
        std::size_t growth_rate() const { return 2; }
    };
}

#endif