#include <iostream>
#include <vector>
#include <array>
#include "../project-headers/vector.h"
#include "../project-headers/array.h"
#include "../project-headers/unique_ptr.h"
#include "../project-headers/shared_ptr.h"
 
int main() 
{
    int* resource = new int {10};
    std::shared_ptr<int> ptr1 {resource};
    std::shared_ptr<int> ptr2 {ptr1};
    std::cout << ptr1.use_count() << "\n";
    std::cout << sizeof(std::shared_ptr<int>) << "\n";
}