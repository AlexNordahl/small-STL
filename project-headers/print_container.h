#ifndef SMALL_STL_PRINT_CONTAINER
#define SMALL_STL_PRINT_CONTAINER

#include <iostream>

namespace sSTL
{
    template<typename It>
    void printContainer(It begin, It end)
    {
        std::cout << "[";
        while (begin != end)
        {
            std::cout << *begin;
            if (++begin != end)
                std::cout << ", ";
        }
        std::cout << "]\n";
    }
}

#endif