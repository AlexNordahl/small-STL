#include <iostream>
#include <vector>
#include "../project-headers/vector.h"

int main()
{

    sSTL::vector<int> vec2 {10};

    for (size_t i = 0; i < vec2.size(); ++i)
    {
        std::cout << vec2.at(i) << " ";
    }
    std::cout << "\n";    

    sSTL::vector<int> vec3(10, 4);

    for (size_t i = 0; i < vec3.size(); ++i)
    {
        std::cout << vec3[i] << " ";
    }
    std::cout << "\n";
}