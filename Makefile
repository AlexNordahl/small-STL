# shortcuts for cmake commands

configure:
	cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug -DBUILD_TESTS=ON

build:
	cmake --build build -j

all: configure build

run:
	./build/main

test:
	ctest --test-dir build --output-on-failure

clean:
	rm -rf build
