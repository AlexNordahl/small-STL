#ifndef SMALL_STL_UNIQUE_PTR
#define SMALL_STL_UNIQUE_PTR

#include <memory>

namespace sSTL
{
    template<typename T, typename Deleter = std::default_delete<T>>
    class unique_ptr
    {
    public:
        explicit unique_ptr(T* resource = nullptr) noexcept { m_resource = resource; }

        unique_ptr(const unique_ptr&) = delete;
        unique_ptr& operator=(const unique_ptr&) = delete;

        unique_ptr(unique_ptr&& other) noexcept
        {
            m_resource = other.m_resource;
            other.m_resource = nullptr;
        }

        unique_ptr& operator= (unique_ptr&& other) noexcept
        {
            if (this == &other)
                return *this;

            clear();

            m_resource = other.m_resource;
            other.m_resource = nullptr;

            return *this;
        }

        T* release() noexcept
        {
            T* temp = m_resource;
            m_resource = nullptr;
            return temp;
        }

        void reset(T* resource = nullptr) noexcept
        {
            if (resource == m_resource)
                return;
            
            clear();
            m_resource = resource;
        }
        
        T* get() noexcept { return m_resource; }
        
        bool isHolding() noexcept { return get() != nullptr;}
        
        explicit operator bool() noexcept { return isHolding(); }
        
        T& operator* () { return *m_resource; }
        T* operator-> () { return m_resource; }
        
        ~unique_ptr() { clear(); }

    private:
        T* m_resource {};

        void clear()
        {
            Deleter deleter;
            deleter(m_resource);
            m_resource = nullptr;
        }
    };

    template<typename T, typename Deleter>
    class unique_ptr<T[], Deleter>
    {
    public:
        explicit unique_ptr(T* resource = nullptr) noexcept { m_resource = resource; }

        unique_ptr(const unique_ptr&) = delete;
        unique_ptr& operator=(const unique_ptr&) = delete;

        unique_ptr(unique_ptr&& other) noexcept
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

        T* release() noexcept
        {
            T* temp = m_resource;
            m_resource = nullptr;
            return temp;
        }

        void reset(T* resource = nullptr) noexcept
        {
            if (resource == m_resource)
                return;

            clear();
            m_resource = resource;
        }
        
        T* get() noexcept { return m_resource; }
        
        bool isHolding() noexcept { return get() != nullptr;}
        
        explicit operator bool() noexcept { return isHolding(); }
        
        T& operator[] (int index) { return m_resource[index]; }

        ~unique_ptr() { clear(); }

    private:
        T* m_resource {};

        void clear()
        {
            Deleter deleter;
            deleter(m_resource);
            m_resource = nullptr;
        }
    };
}

#endif