# C++ Standard Library Implementations

## Motivation
The main goal of this project was to gain a deeper understanding of how the C++ Standard Library works internally by re-implementing simplified versions of its most commonly used components. The purpose was to strengthen understanding of **memory management**, **iterators**, **templates**, and **container design** principles.

This project also served as a practical exercise in clean C++ code organization, header-only libraries, and modern C++ features such as **move semantics**, **RAII**, and **smart pointers**.

---

## Features
- Custom implementations of fundamental STL components:
  - `array`
  - `vector`
  - `unique_ptr`
  - `shared_ptr`
  - `pair`
  - `iterator`
  - `algorithm` (basic algorithms like `reverse`)
- Header-only design for simplicity
- Clear code structure and documentation
---

## Build Instructions

### Prerequisites
- CMake ≥ 3.20  
- C++17 compiler

---

### Quick Start

```bash
# Configure (Debug + tests)
cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug -DBUILD_TESTS=ON

# Build
cmake --build build -j

# Run example
./build/main

# Run tests
ctest --test-dir build --output-on-failure

# Make Shortcuts
make configure
make build
make run
make test
make clean
