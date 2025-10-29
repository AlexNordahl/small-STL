#ifndef SMALL_STL_SHARED_PTR
#define SMALL_STL_SHARED_PTR

#include <cstddef>
#include <atomic>

namespace sSTL
{
    template<typename T>
    struct c_block
    {
        T* m_ref {};
        std::atomic<size_t> m_count {};

        ~c_block() { delete m_ref; }
    };

    template<typename T>
    class shared_ptr
    {
    public:
        shared_ptr() = default;

        shared_ptr(T* ptr)
            : m_block_ptr {new c_block<T> {}}, m_ptr {ptr}
        {
            m_block_ptr->m_ref = ptr;
            m_block_ptr->m_count.store(1);
        }

        shared_ptr(const shared_ptr& other)
        {
            m_ptr = other.m_ptr;
            m_block_ptr = other.m_block_ptr;
            m_block_ptr->m_count.fetch_add(1);
        }

        shared_ptr& operator= (const shared_ptr& other)
        {
            if (this == &other)
                return *this;

            if (m_block_ptr and m_block_ptr->m_count.fetch_sub(1) == 1)
                delete m_block_ptr;

            m_ptr = other.m_ptr;
            m_block_ptr = other.m_block_ptr;
            if (m_block_ptr)
                m_block_ptr->m_count.fetch_add(1);

            return *this;
        }

        shared_ptr(shared_ptr&& other)
        {
            m_ptr = other.m_ptr;
            m_block_ptr = other.m_block_ptr;
            
            other.m_ptr = nullptr;
            other.m_block_ptr = nullptr;
        }

        shared_ptr& operator= (shared_ptr&& other)
        {
            if (this == &other)
                return *this;

            m_ptr = other.m_ptr;
            m_block_ptr = other.m_block_ptr;
            
            other.m_ptr = nullptr;
            other.m_block_ptr = nullptr;

            return *this;
        }

        T* get()
        {
            return m_ptr;
        }
        
        std::size_t use_count() 
        { 
            if (m_block_ptr == nullptr)
                return 0;
            
            return m_block_ptr->m_count.load(); 
        }

        ~shared_ptr()
        {
            if (m_block_ptr and m_block_ptr->m_count.fetch_sub(1) == 1)
                delete m_block_ptr;
        }

    private:
        c_block<T>* m_block_ptr {};
        T* m_ptr {};
    };
}

#endif