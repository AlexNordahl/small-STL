#include <iostream>
#include <vector>
#include <array>
#include "../small-STL-headers/pair.h"
#include "../small-STL-headers/print_container.h"
#include "../small-STL-headers/algorithm.h"
#include "../small-STL-headers/vector.h"
#include "../small-STL-headers/array.h"
#include "../small-STL-headers/unique_ptr.h"
#include "../small-STL-headers/shared_ptr.h"
 
int main() 
{
    sSTL::vector<int> vec {1, 2, 3, 4, 5};

    sSTL::print_container(vec.begin(), vec.end());
    sSTL::print_container(vec.rbegin(), vec.rend());
}