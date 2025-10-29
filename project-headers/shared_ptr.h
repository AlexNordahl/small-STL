#ifndef SMALL_STL_SHARED_PTR
#define SMALL_STL_SHARED_PTR

#include <cstddef>
#include <atomic>

namespace sSTL
{
    template<typename T>
    struct c_block
    {
        std::atomic<long> m_count {};
    };

    template<typename T>
    class shared_ptr
    {
    public:
        shared_ptr()
        {
            std::cout << "Default Ctor Called\n";
            m_block_ptr = new c_block<T> {};
        }

        shared_ptr(T* ptr)
            : shared_ptr()
        {
            std::cout << "Parametrized Ctor Called\n";
            // m_block_ptr->m_ref = ptr;
            m_block_ptr->m_count++;
        }

        shared_ptr(shared_ptr& other)
        {
            std::cout << "Copy Ctor Called\n";
            m_ptr = other.m_ptr;
            m_block_ptr = other.m_block_ptr;
            m_block_ptr->m_count++;
        }
        
        std::size_t use_count() 
        { 
            return m_block_ptr->m_count; 
        }

        ~shared_ptr()
        {
            std::cout << "Destructor Called\n";
            if (m_block_ptr->m_count == 1)
                delete m_block_ptr;
            else
                m_block_ptr->m_count--;
        }

    private:
        T* m_ptr {};
        c_block<T>* m_block_ptr {};
    };
}

#endif