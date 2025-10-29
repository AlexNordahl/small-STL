#include "../project-headers/unique_ptr.h"
#include <gtest/gtest.h>
#include <string>

TEST(UniquePtrConstructor, BasicConstructorNullptr)
{
    sSTL::unique_ptr<int> uptr{};
    EXPECT_EQ(uptr.get(), nullptr);
}

TEST(UniquePtrConstructor, BasicConstructorValue)
{
    sSTL::unique_ptr<int> uptr {new int {10}};
    EXPECT_EQ(*uptr.get(), 10);
}

TEST(UniquePtrMoveSemantics, MoveConstructor)
{
    sSTL::unique_ptr<int> uptr1 {new int {10}};
    sSTL::unique_ptr<int> uptr2 {std::move(uptr1)};

    EXPECT_EQ(uptr1.get(), nullptr);
    EXPECT_EQ(*uptr2.get(), 10);
}

TEST(UniquePtrMoveSemantics, MoveAssignmentOperator)
{
    sSTL::unique_ptr<int> uptr1 {new int {10}};
    sSTL::unique_ptr<int> uptr2 {};
    uptr2 = std::move(uptr1);

    EXPECT_EQ(uptr1.get(), nullptr);
    EXPECT_EQ(*uptr2.get(), 10);
}

TEST(UniquePtrMethods, Release)
{
    sSTL::unique_ptr<int> uptr {new int {10}};
    
    int* number_ptr = uptr.release();

    EXPECT_EQ(uptr.get(), nullptr);
    EXPECT_EQ(*number_ptr, 10);

    delete number_ptr;
}

TEST(UniquePtrMethods, Reset)
{
    sSTL::unique_ptr<int> uptr {new int {10}};
    
    uptr.reset(new int {20});

    EXPECT_EQ(*uptr.get(), 20);
}

TEST(UniquePtrMethods, Get)
{
    sSTL::unique_ptr<int> uptr {new int {10}};
    
    int* number_ptr = uptr.get();

    EXPECT_EQ(*uptr.get(), 10);
    EXPECT_EQ(*number_ptr, 10);
}