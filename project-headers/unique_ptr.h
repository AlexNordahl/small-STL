#ifndef SMALL_STL_UNIQUE_PTR
#define SMALL_STL_UNIQUE_PTR

#include <memory>

namespace sSTL
{
    template<typename T, typename Deleter = std::default_delete<T>>
    class unique_ptr
    {
    public:
        unique_ptr(T* resource)
        {
            m_resource = resource;
        }

        ~unique_ptr()
        {
            Deleter deleter;
            deleter(resource);
        }
    private:
        T* m_resource {};
    };
}

#endif