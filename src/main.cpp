#include <iostream>
#include <vector>
#include "../project-headers/vector.h"

struct A
{
    int c {};
};

int main()
{
    sSTL::vector<A> vec {};
    for (int i = 0; i < 10; i++)
    {
        vec.push_back({i});
        std::cout << vec.size() << " " << vec.capacity() << "\n";
    }

    sSTL::vector<A> vec2 {std::move(vec)};

    std::cout << vec.size() << " " << vec.capacity() << "\n";
    std::cout << vec2.size() << " " << vec2.capacity() << "\n";
}