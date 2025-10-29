#ifndef SMALL_STL_UNIQUE_PTR
#define SMALL_STL_UNIQUE_PTR

#include <memory>

namespace sSTL
{
    template<typename T, typename Deleter = std::default_delete<T>>
    class unique_ptr final
    {
    public:
        unique_ptr(T* resource = nullptr) { m_resource = resource; }

        unique_ptr(const unique_ptr&) = delete;
        unique_ptr& operator=(const unique_ptr&) = delete;

        unique_ptr(unique_ptr&& other)
        {
            m_resource = other.m_resource;
            other.m_resource = nullptr;
        }

        unique_ptr& operator= (unique_ptr&& other)
        {
            if (this == &other)
                return *this;

            clear();

            m_resource = other.m_resource;
            other.m_resource = nullptr;

            return *this;
        }

        T* release()
        {
            T* temp = m_resource;
            m_resource = nullptr;
            return temp;
        }

        void reset(T* resource)
        {
            clear();
            m_resource = resource;
        }
        
        T* get() { return m_resource; }
        
        bool isHolding() { return get() != nullptr;}
        
        explicit operator bool() { return isHolding(); }
        
        T& operator* () { return *m_resource; }
        T* operator-> () { return m_resource; }
        
        ~unique_ptr() { clear(); }

        private:
        T* m_resource {};

        void clear() // Leaves m_resource in unspecified state
        {
            Deleter deleter;
            deleter(m_resource);
        }
    };
}

#endif