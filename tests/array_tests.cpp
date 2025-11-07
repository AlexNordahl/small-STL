#include "../small-STL-headers/array.h"
#include <gtest/gtest.h>
#include <string>
#include <stdexcept>

TEST(ArrayBasic, SizeAndEmptyForNonZeroN)
{
    sSTL::array<int, 5> a;
    EXPECT_EQ(a.size(), 5);
    EXPECT_FALSE(a.empty());
}

TEST(ArrayBasic, SizeAndEmptyForZeroN)
{
    sSTL::array<int, 0> a;
    EXPECT_EQ(a.size(), 0);
    EXPECT_TRUE(a.empty());
}

TEST(ArrayInitialization, ValueInitializationZeroesInts)
{
    sSTL::array<int, 4> a{};
    for (std::size_t i = 0; i < a.size(); ++i)
        EXPECT_EQ(a[i], 0);
}

TEST(ArrayAccess, SubscriptAllowsReadAndWrite)
{
    sSTL::array<int, 3> a{};
    a[0] = 10;
    a[1] = 20;
    a[2] = 30;

    EXPECT_EQ(a[0], 10);
    EXPECT_EQ(a[1], 20);
    EXPECT_EQ(a[2], 30);
}

TEST(ArrayAccess, AtReturnsReferenceAndChecksBounds)
{
    sSTL::array<int, 2> a{};
    a.at(0) = 42;
    EXPECT_EQ(a.at(0), 42);

    EXPECT_THROW(a.at(2), std::out_of_range);
    EXPECT_THROW(a.at(100), std::out_of_range);
}

TEST(ArrayAccess, ConstAtChecksBounds)
{
    sSTL::array<int, 2> a{};
    a[0] = 7;
    a[1] = 9;

    const auto& ca = a;
    EXPECT_EQ(ca.at(0), 7);
    EXPECT_EQ(ca.at(1), 9);
    EXPECT_THROW(ca.at(2), std::out_of_range);
}

TEST(ArrayFrontBack, AccessFirstAndLast)
{
    sSTL::array<int, 3> a{};
    a[0] = 1;
    a[1] = 2;
    a[2] = 3;

    EXPECT_EQ(a.front(), 1);
    EXPECT_EQ(a.back(), 3);

    a.front() = 10;
    a.back() = 30;
    EXPECT_EQ(a[0], 10);
    EXPECT_EQ(a[2], 30);

    const auto& ca = a;
    EXPECT_EQ(ca.front(), 10);
    EXPECT_EQ(ca.back(), 30);
}

TEST(ArrayData, ReturnsPointerToContiguousStorage)
{
    sSTL::array<int, 4> a{};
    a[0] = 11;
    a[1] = 22;

    int* ptr = a.data();
    ASSERT_NE(ptr, nullptr);
    EXPECT_EQ(ptr, &a[0]);
    EXPECT_EQ(*(ptr + 0), 11);
    EXPECT_EQ(*(ptr + 1), 22);

    const auto& ca = a;
    const int* cptr = ca.data();
    ASSERT_NE(cptr, nullptr);
    EXPECT_EQ(cptr, &ca[0]);
    EXPECT_EQ(*(cptr + 1), 22);
}

TEST(ArrayModifiers, FillSetsAllElementsToValue_Int)
{
    sSTL::array<int, 5> a{};
    a.fill(123);

    for (std::size_t i = 0; i < a.size(); ++i)
        EXPECT_EQ(a[i], 123);
}

TEST(ArrayModifiers, FillWorksWithNonTrivialTypes)
{
    sSTL::array<std::string, 3> a{};
    a.fill(std::string("hello"));

    for (std::size_t i = 0; i < a.size(); ++i)
        EXPECT_EQ(a[i], "hello");
}

TEST(ArrayConstCorrectness, MethodsAreAvailableOnConstObjects)
{
    sSTL::array<int, 2> a{};
    a[0] = 5;
    a[1] = 8;

    const auto& ca = a;
    EXPECT_EQ(ca.size(), 2);
    EXPECT_FALSE(ca.empty());
    EXPECT_EQ(ca.front(), 5);
    EXPECT_EQ(ca.back(), 8);
    EXPECT_EQ(ca[0], 5);
    EXPECT_EQ(*ca.data(), 5);
}