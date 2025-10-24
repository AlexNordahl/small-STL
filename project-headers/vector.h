#ifndef SMALL_STL_VECTOR
#define SMALL_STL_VECTOR

#include <memory>
#include <initializer_list>
#include <utility>

namespace sSTL
{
    template<typename T, typename Allocator = std::allocator<T>>
    class vector
    {
    public:
        vector() = default;

        vector(size_t size)
            : m_size {size}, m_capacity {size}
        {
            Allocator allocator;
            m_memory = allocator.allocate(m_capacity);
            for (size_t i = 0; i < m_size; ++i)
            {
                allocator.construct(&m_memory[i], T{});
            }
        }

        vector(std::initializer_list<T> list)
            : m_size {list.size()}, m_capacity {list.size()}
        {
            Allocator allocator;
            m_memory = allocator.allocate(m_capacity);

            size_t i {};
            for (const auto& item : list)
            {
                allocator.construct(&m_memory[i++], item);
            }
        }
        
        vector(vector& other)
        {
            copy_from(other);
        }

        vector(vector&& other)
        {
            move_from(other);
        }

        vector& operator=(vector& other)
        {
            copy_from(other);
            return *this;
        }

        vector& operator=(vector&& other)
        {
            move_from(other);
            return *this;
        }

        T& at(size_t index) { return m_memory[index]; };
        T& operator[] (size_t index) { return m_memory[index]; };

        size_t size() const { return m_size; };
        size_t capacity() const { return m_capacity; };

        void push_back(const T& element)
        {
            Allocator allocator;
            if (m_size < m_capacity)
            {
                allocator.construct(&m_memory[m_size++], element);
                return;
            }

            size_t new_capacity {m_capacity == 0 ? 1 : m_size * growth_rate};
            T* new_memory = allocator.allocate(new_capacity);

            for (size_t i = 0; i < m_size; ++i)
            {
                allocator.construct(&new_memory[i], m_memory[i]);
            }
            allocator.construct(&new_memory[m_size++], element);
            
            for (size_t i = 0; i < m_size; ++i)
            {
                allocator.destroy(&m_memory[i]);
            }
            allocator.deallocate(m_memory, m_capacity);
            
            m_memory = new_memory;
            m_capacity = new_capacity;
        }

        ~vector() 
        { 
            Allocator allocator;
            for (size_t i = 0; i < m_size; ++i)
                allocator.destroy(&m_memory[i]);
            
            if (m_memory)
                allocator.deallocate(m_memory, m_capacity); 
        };

    private:
        size_t m_size {};
        size_t m_capacity {};
        T* m_memory {};
        static constexpr size_t max_size {1'000'000};
        static constexpr int growth_rate {2};

        void copy_from(vector& other)
        {
            Allocator allocator;
            T* new_memory = allocator.allocate(other.m_capacity);

            for (size_t i = 0; i < other.m_size; ++i)
                allocator.construct(&m_memory[i], other.m_memory[i]);

            if (m_memory != nullptr)
            {
                for (size_t i = 0; i < m_size; ++i)
                {
                    allocator.destroy(&m_memory[i]);
                }
                allocator.deallocate(m_memory, m_capacity);
            }

            m_memory = new_memory;
            m_size = other.m_size;
            m_capacity = other.m_capacity;
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
    };
}

#endif