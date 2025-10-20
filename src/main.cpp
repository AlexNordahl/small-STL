#include <iostream>
#include <vector>
#include "../project-headers/vector.h"

struct A
{
    int c {10};
};


int main()
{
    sSTL::vector<int> svec {};
    std::cout << svec.size() << " " << svec.capacity() << "\n";

    std::vector<int> vec {};
    std::cout << vec.size() << " " << vec.capacity() << "\n";
    vec.push_back(10);
    std::cout << vec.size() << " " << vec.capacity() << "\n";
}