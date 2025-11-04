#include <iostream>
#include <vector>
#include <array>
#include "../project-headers/vector.h"
#include "../project-headers/array.h"
#include "../project-headers/unique_ptr.h"
#include "../project-headers/shared_ptr.h"
 
int main() 
{
    sSTL::array<int, 5> arr {1, 2, 3, 4, 5};

    for (auto it {arr.rbegin()}; it != arr.rend(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << "\n";
    
    sSTL::array<int, 5> arr2 {1, 2, 3, 4, 5};
    auto rIt = arr2.rbegin();
    std::cout << *rIt << "\n";
    rIt += 3;
    std::cout << *rIt << "\n";
    rIt -= 3;
    std::cout << *rIt << "\n";
}