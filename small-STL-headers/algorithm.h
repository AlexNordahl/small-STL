#ifndef SMALL_STL_ALGORITHM
#define SMALL_STL_ALGORITHM

namespace sSTL
{
    template<typename It>
    void reverse(It begin, It end)
    {
        if (begin == end)
            return;
            
        --end;
        while (begin < end) 
        {
            auto tmp = *begin;
            *begin = *end;
            *end = tmp;
            ++begin;
            --end;
        }
    }
}

#endif