#include <iostream>
#include "../small-STL-headers/pair.h"
#include "../small-STL-headers/print_container.h"
#include "../small-STL-headers/algorithm.h"
#include "../small-STL-headers/vector.h"
#include "../small-STL-headers/array.h"
#include "../small-STL-headers/unique_ptr.h"
#include "../small-STL-headers/shared_ptr.h"

int main() 
{
    std::cout << "-- vector, pair, move semantics --\n";
    sSTL::vector pair_vector {sSTL::make_pair(1, 2), {3, 4}, {5, 6}};

    for (auto& [f, s] : pair_vector)
        std::cout << "(" << f << ", " << s << ") ";
    std::cout << "\n";

    auto moved_vec {std::move(pair_vector)};

    for (auto& [f, s] : moved_vec)
        std::cout << "(" << f << ", " << s << ") ";
    std::cout << "\n\n";

    std::cout << "-- iterators, reverse --\n";
    sSTL::vector v {1, 2, 3, 4, 5, 6};
    sSTL::print_container(v.begin(), v.end());
    sSTL::reverse(v.begin(), v.end());
    sSTL::print_container(v.begin(), v.end());
    sSTL::reverse(v.begin(), v.end() - 3);
    sSTL::print_container(v.begin(), v.end());
    sSTL::print_container(v.rbegin(), v.rend());

    std::cout << "-- smart pointers --\n";
    sSTL::unique_ptr<int> uptr1 {new int {10}};
    sSTL::unique_ptr<int> uptr2 {new int {20}};
    std::cout << "uptr1: " << *uptr1 << "\n";
    std::cout << "uptr2: " << *uptr2 << "\n";
    uptr1 = std::move(uptr2);
    std::cout << "after move:\n";
    std::cout << "uptr1: " << *uptr1 << "\n";
    std::cout << "uptr2: nullptr" << "\n";
}