#include <iostream>
#include <vector>
#include <array>
#include "../project-headers/vector.h"
#include "../project-headers/array.h"
#include "../project-headers/unique_ptr.h"
 
int main() 
{
    sSTL::unique_ptr<int> ptr1 (new int {10});
    sSTL::unique_ptr<int> ptr2 (new int {4});
    std::cout << "ptr1: " << *ptr1.get() << "\n";
    std::cout << "ptr2: " << *ptr2.get() << "\n";

    ptr2 = std::move(ptr1);
    
    std::cout << "ptr1: " << ptr1.get() << "\n";
    std::cout << "ptr2: " << *ptr2.get() << "\n";
}