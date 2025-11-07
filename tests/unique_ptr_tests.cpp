#include "../small-STL-headers/unique_ptr.h"
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

TEST(UniquePtrArrayConstructor, BasicConstructorNullptr)
{
    sSTL::unique_ptr<int[]> uptr{};
    EXPECT_EQ(uptr.get(), nullptr);
}

TEST(UniquePtrArrayConstructor, BasicConstructorValues)
{
    sSTL::unique_ptr<int[]> uptr { new int[3]{1, 2, 3} };

    ASSERT_NE(uptr.get(), nullptr);
    EXPECT_EQ(uptr[0], 1);
    EXPECT_EQ(uptr[1], 2);
    EXPECT_EQ(uptr[2], 3);
}

TEST(UniquePtrArrayMoveSemantics, MoveConstructor)
{
    sSTL::unique_ptr<int[]> uptr1 { new int[3]{1, 2, 3} };
    sSTL::unique_ptr<int[]> uptr2 { std::move(uptr1) };

    EXPECT_EQ(uptr1.get(), nullptr);
    ASSERT_NE(uptr2.get(), nullptr);
    EXPECT_EQ(uptr2[0], 1);
    EXPECT_EQ(uptr2[1], 2);
    EXPECT_EQ(uptr2[2], 3);
}

TEST(UniquePtrArrayMoveSemantics, MoveAssignmentOperator)
{
    sSTL::unique_ptr<int[]> uptr1 { new int[2]{10, 20} };
    sSTL::unique_ptr<int[]> uptr2 {};
    uptr2 = std::move(uptr1);

    EXPECT_EQ(uptr1.get(), nullptr);
    ASSERT_NE(uptr2.get(), nullptr);
    EXPECT_EQ(uptr2[0], 10);
    EXPECT_EQ(uptr2[1], 20);
}

TEST(UniquePtrArrayMethods, Release)
{
    sSTL::unique_ptr<int[]> uptr { new int[2]{10, 20} };

    int* arr_ptr = uptr.release();

    EXPECT_EQ(uptr.get(), nullptr);
    ASSERT_NE(arr_ptr, nullptr);
    EXPECT_EQ(arr_ptr[0], 10);
    EXPECT_EQ(arr_ptr[1], 20);

    delete[] arr_ptr;
}

TEST(UniquePtrArrayMethods, ResetToNewArray)
{
    sSTL::unique_ptr<int[]> uptr { new int[3]{1, 2, 3} };

    uptr.reset(new int[3]{4, 5, 6});

    ASSERT_NE(uptr.get(), nullptr);
    EXPECT_EQ(uptr[0], 4);
    EXPECT_EQ(uptr[1], 5);
    EXPECT_EQ(uptr[2], 6);
}

TEST(UniquePtrArrayMethods, ResetToNullptr)
{
    sSTL::unique_ptr<int[]> uptr { new int[1]{42} };

    uptr.reset(nullptr);

    EXPECT_EQ(uptr.get(), nullptr);
}

TEST(UniquePtrArrayMethods, Get)
{
    sSTL::unique_ptr<int[]> uptr { new int[3]{7, 8, 9} };

    int* raw = uptr.get();

    ASSERT_NE(raw, nullptr);
    EXPECT_EQ(uptr[0], 7);
    EXPECT_EQ(uptr[1], 8);
    EXPECT_EQ(uptr[2], 9);

    EXPECT_EQ(raw[0], 7);
    EXPECT_EQ(raw[1], 8);
    EXPECT_EQ(raw[2], 9);
}

TEST(UniquePtrArrayMethods, IndexingAfterMove)
{
    sSTL::unique_ptr<int[]> uptr1 { new int[4]{11, 22, 33, 44} };
    sSTL::unique_ptr<int[]> uptr2 { std::move(uptr1) };

    EXPECT_EQ(uptr1.get(), nullptr);
    ASSERT_NE(uptr2.get(), nullptr);
    EXPECT_EQ(uptr2[0], 11);
    EXPECT_EQ(uptr2[1], 22);
    EXPECT_EQ(uptr2[2], 33);
    EXPECT_EQ(uptr2[3], 44);
}