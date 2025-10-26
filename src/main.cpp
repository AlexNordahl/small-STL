#include <iostream>
#include <vector>
#include <array>
#include "../project-headers/vector.h"
#include "../project-headers/array.h"

int main()
{
    sSTL::array<int, 5> arr {1, 2, 3, 4, 5};

    std::cout << arr.at(3) << "\n";
    std::cout << arr.empty() << "\n";
    std::cout << arr.size() << "\n";
}