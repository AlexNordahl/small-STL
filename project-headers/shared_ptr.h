#ifndef SMALL_STL_SHARED_PTR
#define SMALL_STL_SHARED_PTR

#include <cstddef>

namespace sSTL
{
    template<typename T>
    class shared_ptr
    {
    public:

    private:
        T* m_ptr {};
        std::size_t m_count {};
    };
}

#endif