#include <iostream>
#include <vector>
#include <array>
#include "../project-headers/pair.h"
#include "../project-headers/print_container.h"
#include "../project-headers/algorithm.h"
#include "../project-headers/vector.h"
#include "../project-headers/array.h"
#include "../project-headers/unique_ptr.h"
#include "../project-headers/shared_ptr.h"
 
int main() 
{
    sSTL::vector<int> vec {1, 2, 3, 4, 5};

    sSTL::print_container(vec.begin(), vec.end());
    sSTL::print_container(vec.rbegin(), vec.rend());
}