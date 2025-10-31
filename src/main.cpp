#include <iostream>
#include <vector>
#include <array>
#include "../project-headers/vector.h"
#include "../project-headers/array.h"
#include "../project-headers/unique_ptr.h"
#include "../project-headers/shared_ptr.h"
 
int main() 
{
    sSTL::vector<int> vec {1, 2, 3, 4, 5};

    for (auto it {vec.begin()}; it != vec.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << "\n";

    sSTL::array<int, 5> arr {1, 2, 3, 4, 5};

    for (auto it {arr.begin()}; it != arr.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << "\n";
}