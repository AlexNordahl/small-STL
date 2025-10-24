#include <iostream>
#include <vector>
#include "../project-headers/vector.h"

struct A
{
    int c {};
};

int main()
{
    // sSTL::vector<A> vec {{1}, {2}, {3}};

    // for (size_t i = 0; i < vec.size(); i++)
    // {
    //     std::cout << vec[i].c << " ";
    // }
    // std::cout << "\n";

    // vec.push_back({4});

    // for (size_t i = 0; i < vec.size(); i++)
    // {
    //     std::cout << vec[i].c << " ";
    // }
    // std::cout << "\n";

    sSTL::vector<A> vec {};
    for (int i = 0; i < 10; i++)
    {
        vec.push_back({i});
        std::cout << vec.size() << " " << vec.capacity() << "\n";
    }
    
}