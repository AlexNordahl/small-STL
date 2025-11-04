#include <iostream>
#include <vector>
#include <array>
#include "../project-headers/print_container.h"
#include "../project-headers/algorithm.h"
#include "../project-headers/vector.h"
#include "../project-headers/array.h"
#include "../project-headers/unique_ptr.h"
#include "../project-headers/shared_ptr.h"
 
int main() 
{
    sSTL::array<int, 5> arr {1, 2, 3, 4, 5};
    sSTL::printContainer(arr.begin(), arr.end());
    sSTL::reverse(arr.begin(), arr.end());
    sSTL::printContainer(arr.begin(), arr.end());
}